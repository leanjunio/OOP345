#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

namespace sict
{
	int INITIAL = 3;

	String::String(const char * string)
		// create an object from the passed 'string' parameter
	{
		// check for null address
		// set 'm_string' to hold an empty string if nulled
		if (string == nullptr)
			m_string = nullptr;
		else
		{
			// copy the value of 'string' into 'm_string'
			m_string = new char[std::strlen(string)];
			for (size_t i = 0; i < std::strlen(string); i++)
			{
				m_string[i] = string[i];
				m_string[std::strlen(string)] = '\0';
			}
		}
	}

	void String::display(std::ostream & os) const
	{
		os << m_string;
	}

	std::ostream& operator<<(std::ostream & os, String& s)
	{
		os << INITIAL++ << ": ";
		s.display(os);
		return os;
	}
}
