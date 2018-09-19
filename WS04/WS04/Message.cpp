#include <iostream>
#include <fstream>
#include <string>
#include "Message.h"

namespace w4
{
	Message::Message()
		: m_Delimeter{'\0'},
		m_Message{""},
		m_Reply{""},
		m_Tweet{""},
		m_User{""}
	{
	}

	Message::Message(std::ifstream & in, char c)
		: m_Delimeter{c}
	{
		std::string temp;

		while (std::getline(in, temp))
		{
			m_User = temp.substr(0, temp.find(" "));	// get the first word
			
			// find the index of '@'
			size_t atSymbol = temp.find('@');

			if (atSymbol != -1)
				m_Reply = temp.substr(atSymbol, temp.find(' '));

			std::cout << m_Reply << std::endl;
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