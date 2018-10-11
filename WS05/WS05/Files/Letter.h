// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 10/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _SICT_LETTER_H
#define _SICT_LETTER_H

#include <string>

namespace sict
{
	// Enumeration constant that identifies the letter grades in a course
	enum class Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

	// A template function that converts each enumeration constant into a C-style null-terminated string
	// Receive an unmodifiable reference to one of the enumeration constants
	// Returns the address of string that represents that constant
	template <typename Letter>
	std::string convert(const Letter& letter)
	{
		std::string grade = "";

		if (letter == Letter::Aplus)
			grade = "A+";
		else if (letter == Letter::A)
			grade = "A";
		else if (letter == Letter::Bplus)
			grade = "B+";
		else if (letter == Letter::B)
			grade = "B";
		else if (letter == Letter::Cplus)
			grade = "C+";
		else if (letter == Letter::C)
			grade = "C";
		else if (letter == Letter::Dplus)
			grade = "D+";
		else if (letter == Letter::D)
			grade = "D";
		else
			grade = "F";

		return grade;
	}
}

#endif // !_SICT_LETTER_H

