// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 6/4/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _W1_CSTRING_H
#define _W1_CSTRING_H

#include <iostream>

namespace w1
{
	class CString
	{
		const int MAX;
		char m_String[10];
	public:
		CString();
		CString(const char* string);
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, CString& string);
}

#endif // !_W1_CSTRING_H



