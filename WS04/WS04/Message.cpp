#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w4
{
	Message::Message(void)
		// Default constructor for safe-empty check
		: Message("", "", "", "", '\0')
	{
	}

	Message::Message(String message, String user, String tweet, String reply, char delimeter)
		// Parameterized constructor that creates an object based on the parameters
		: m_Message{message}
		, m_User{user}
		, m_Tweet{tweet}
		, m_Reply{reply}
		, m_Delimeter{delimeter}
	{
	}

	Message::Message(std::ifstream & in, char c)
		// Retrieves an ifstream for the file, parses the file into different Message objects
		// Create a temporary object that can fill the members
	{
		std::string line;

		while (std::getline(in, line))
		{
			Message temp;

			// Get the user
			temp.m_User = line.substr(0, line.find(" "));	
			
			// Erase the user from the line
			// find position of the user
			size_t p_User = line.find(temp.m_User);
			std::cout << "user's position: " << p_User << std::endl;

			// position of @
			size_t atSymbol = line.find('@');

			// If there's an '@' in the string
			// That means there's a reply
			// EraseTake the reply into m_Reply
			if (atSymbol != -1)
			{

			}
			else m_Reply = { "" };

			std::cout << "Current m_Reply [" << &temp.m_Reply << "]: " << temp.m_Reply << std::endl;
		}
	}

	Message::~Message()
	{
		std::cout << "Called " << this << " ~Message()" << std::endl;
	}

	bool Message::empty() const
	{
		return (m_Message.empty() && m_User.empty() && m_Tweet.empty() && m_Reply.empty() && m_Delimeter == '\0');
	}

	void Message::display(std::ostream & os) const
	{
		os << "Message\n" << " User  : " << this->m_User << "\n";

		if (this->m_Reply.length() > 0)
			os << " Reply : " << m_Reply << "\n";
		
		os << " Tweet : " << m_Tweet << std::endl;
	}
}
