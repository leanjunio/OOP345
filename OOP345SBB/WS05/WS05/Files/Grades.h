// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 10/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _SICT_GRADES_H
#define _SICT_GRADES_H

#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include "Letter.h"

namespace sict
{
	/// Holds the grades for all students in a course
	/// When instantiated, receive filename (ifstream) containing all students in the course
	/// Store all the grades dynamically
	/// Each row in the file contains: (studentNumber) and (gradeValue)
	/// If the file cannot be opened, throw an exception
	class Grades
	{
		int* m_StudentNumbers;
		double* m_Grades;
		int m_LineCount;
	public:
		Grades(const Grades&) = delete;
		Grades(const Grades&&) = delete;
		Grades& operator=(const Grades&) = delete;
		Grades&& operator=(Grades&&) = delete;

		/// Receives a reference to the output stream (os) as well as the address of the expression to be used (F) to determine the letter grade
		/// Displays the student number, student grade, and letter equivalent (using the template function in Letter.h)
		void displayGrades(std::ostream&, std::string (*letter)(float)) const;
		Grades(const char* file);
		int countLines(std::ifstream&);
		void readFile(std::ifstream&);
	};
}

#endif // !_SICT_GRADES_H



