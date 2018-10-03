// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _SICT_GRADES_H
#define _SICT_GRADES_H

#include <iostream>

namespace sict
{
	/// Holds the grades for all students in a course
	/// When instantiated, receive filename (ifstream) containing all students in the course
	/// Store all the grades dynamically
	/// Each row in the file contains: (studentNumber) and (gradeValue)
	/// If the file cannot be opened, throw an exception
	class Grades
	{
	public:
		/// Receives a reference to the output stream (os) as well as the address of the expression to be used (F)
		void displayGrades(std::ostream&, F) const;
		Grades();
		~Grades();
	};
}

#endif // !_SICT_GRADES_H



