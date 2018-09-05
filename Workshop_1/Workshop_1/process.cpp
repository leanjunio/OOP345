// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 6/4/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "CString.h"
#include "process.h"

namespace w1
{
	void process(const char * string, std::ostream & os)
	{
		static int counter = 0;
		CString str(string);
		os << counter++ << ": " << str << std::endl;
	}
}

