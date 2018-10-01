// Name: Lean Junio
// Seneca Student ID: 019109123
// Seneca email: ljjunio@myseneca.ca	
// Date of completion: 10/1/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Message.h"

namespace w4
{
	Message::Message()
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
		String ln;

		// Read the file into lines
		std::getline(in, ln, c);

		String user, reply, tweet;
		Message temp;

		// Take the user and erase it from the line
		user = ln.substr(0, ln.find(' '));

		// find the position of user and the next space and delete them
		auto userPOS = ln.find(user);
		ln.erase(userPOS, user.length() + 1);

		// Check if there is a reply tagged
		// if so, save it
		bool replyExists = ln.find('@') != static_cast<size_t>(-1);
			
		if (replyExists)
		{
			ln.erase(0, 1);
			reply = ln.substr(0, ln.find(' '));
			ln.erase(ln.find(reply), ln.find(' ') + 1);
		}
		else 
			reply = "";

		// let tweet get the remaining string in 'ln'
		tweet = ln;

		// check if at least tweet and user exists
		// if so, create an object
		bool ifTweetExists = !tweet.empty();

		if (ifTweetExists)
			*this = Message(user, tweet, reply);

		// display(std::cout);
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
		
		os << " Tweet : " << m_Tweet << "\n\n";
	}
}
