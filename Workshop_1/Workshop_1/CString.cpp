// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 6/4/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <cstring>
#include <iostream>
#include "CString.h"

int STORED = 3;

namespace w1
{
	// Safe-empty state constructor
	//
	CString::CString()
		: MAX{ 0 }, m_String{ '\0' }
	{
	}

	// Param: address of a C-style null-terminated string
	// Desc: stores the first MAX characters of the string
	// Initialize MAX to the value of STORED
	//
	CString::CString(const char * string)
		: MAX{ STORED }
	{
		if (string == nullptr)
			m_String[0] = '\0';
		else
		{
			std::strncpy(m_String, string, MAX);
			m_String[MAX + 1] = '\0';
		}
	}
	void CString::display(std::ostream & os) const
	{
		os << m_String;
	}

	std::ostream& operator<<(std::ostream& os, CString& string)
	{
		string.display(os);
		return os;
	}
}
