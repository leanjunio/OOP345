#include <iostream>
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

	}

	void Message::display(std::ostream & os) const
	{
		os << "Message\n" << " User  : " << this->m_User << "\n";

		if (this->m_Reply.length() > 0)
			os << " Reply : " << m_Reply << "\n";
		
		os << " Tweet : " << m_Tweet << std::endl;
	}

	Message::~Message()
	{
	}
}
