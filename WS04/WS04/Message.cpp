#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w4
{
	Message::Message(void)
		: m_Delimeter{'\0'}
		, m_Message{""}
		, m_Reply{""}
		, m_Tweet{""}
		, m_User{""}
	{
	}

	Message::Message(String message, String user, String tweet, String reply, char delimeter)
		: m_Message{message}
		, m_User{user}
		, m_Tweet{tweet}
		, m_Reply{reply}
		, m_Delimeter{delimeter}
		// Constructor that allows parametric construction of Message object
	{
	}

	Message::Message(std::ifstream & in, char c)
		: m_Delimeter{c}
		// Retrieves an ifstream for the file, parses the file into different Message objects
	{
		std::string line;

		while (std::getline(in, line))
		{
			Message temp;
			std::string currentLine = line;
			temp.m_User = currentLine.substr(0, currentLine.find(" "));	// get the first word
			
			std::cout << "Current temp: " << currentLine << std::endl;
			// find the index of '@'
			size_t atSymbol = currentLine.find('@');

			if (atSymbol != -1)
				temp.m_Reply = currentLine.substr(atSymbol, currentLine.find(' '));

			std::cout << "Current m_Reply [" << &temp.m_Reply << "]: " << temp.m_Reply << std::endl;
		}
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
