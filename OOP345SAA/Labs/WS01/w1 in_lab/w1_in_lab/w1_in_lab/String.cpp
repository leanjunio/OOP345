#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"

extern int INITIAL;

namespace sict
{
	String::String(const char * string)
		// create an object from the passed 'string' parameter
	{
		// check for null address
		// set 'm_string' to hold an empty string if nulled
		if (string == nullptr)
			m_string[0] = '\0';
		else
		{
			// copy the first 3 characters of the string
			// add null at the end
			std::strncpy(m_string, string, 3);
			m_string[3] = '\0';
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
