// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _SICT_LETTER_H
#define _SICT_LETTER_H

namespace sict
{
	/// Enumeration constant that identifies the letter grades in a course
	enum Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

	/// A template function that converts each enumeration constant into a C-style null-terminated string
	/// Receive an unmodifiable reference to one of the enumeration constants
	/// Returns the address of string that represents that constant
	const char* convert(const Letter& letter)
	{
		if (letter == Aplus)
			return "A+";
		else if (letter == A)
			return "A";
		else if (letter == Bplus)
			return "B+";
		else if (letter == B)
			return "B";
		else if (letter == Cplus)
			return "C+";
		else if (letter == C)
			return "C";
		else if (letter == Dplus)
			return "D+";
		else if (letter == D)
			return "D";
		else
			return "F";
	}
	
}

#endif // !_SICT_LETTER_H

