#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Message.h"

namespace w4
{
	int Message::indexer = 0;

	Message::Message(void)
		// Default constructor for safe-empty check
		: Message("", "", "")
	{
	}

	Message::Message(String user, String tweet, String reply)
		// Parameterized constructor that creates an object based on the parameters
		: m_User{user}
		, m_Tweet{tweet}
		, m_Reply{reply}
	{
	}

	Message::Message(std::ifstream & in, char c)
		// Retrieves
		// Retrieves an ifstream for the file, parses the file into different Message objects
		// Create a temporary object that can fill the members
	{
		std::vector<std::string> line;
		std::string ln;

		// Read the file into lines
		while (std::getline(in, ln, c))
			line.push_back(ln);

		// Parse all the lines in the vector
		for (std::string ln : line)
		{
			std::string user, reply, tweet;
			Message temp;

			// Take the user and erase it from the line
			user = ln.substr(0, ln.find(' '));
			ln.erase(ln.find(user), ln.find(' ') + 1);

			// Check if there is a reply tagged
			// if so, save it
			bool replyExists = ln.find('@') != -1;
			
			if (replyExists)
			{
				reply = ln.substr(0, ln.find(' '));
				ln.erase(ln.find(reply), ln.find(' ') + 1);
			}
			else 
				reply = "";

			// let tweet get the remaining string in 'ln'
			tweet = ln;

			// check if at least tweet and user exists
			// if so, create an object
			bool check = (tweet.size() > 0 && user.size() > 0);

			if (!check)
			{
				Message non("", "", '\0');
				*this = non;
			}
			else
			{
				Message t(user, tweet, reply);
				*this = t;
			}
		}

		std::cout << line.size() << std::endl;
	}

	Message::~Message()
	{
	}

	bool Message::empty() const
	{
		return (m_User.empty() && m_Tweet.empty() && m_Reply.empty());
	}

	void Message::display(std::ostream & os) const
	{
		os << "Message\n" << " User  : " << this->m_User << "\n";

		if (this->m_Reply.length() > 0)
			os << " Reply : " << m_Reply << "\n";
		
		os << " Tweet : " << m_Tweet << std::endl;
	}

	std::string readNthLine(std::ifstream & in, int N)
		// Reads the line 'N' in the passed file
		// returns the line of the string at N
	{
		std::string s;

		// Skip N amount of lines
		for (int i = 0; i < N; i++)
			std::getline(in, s);

		std::getline(in, s);
		return s;
	}
}
