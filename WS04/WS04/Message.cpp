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
		// Retrieves an ifstream for the file, parses the file into different Message objects
		// Create a temporary object that can fill the members
	{
		//std::vector<String> line;
		String ln;

		// Read the file into lines

		std::getline(in, ln, c);

		String user, reply, tweet;
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
			*this = Message("", "", '\0');	// ERROR OCCURS AT END OF PROGRAM
		}
		else
		{
			*this = Message(user, tweet, reply);
		}

		display(std::cout);
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
}
