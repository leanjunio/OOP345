// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <string>
#include <iostream>
#include "Grades.h"

namespace sict
{
	void Grades::displayGrades(std::ostream & os, Letter letter) const
	{

	}
	Grades::Grades(const char* file)
	{	
		if (file != nullptr && file[0] != '\0')
		{
			int numLines = 0;

			std::ifstream grades_file(file);
			numLines = countLines(grades_file);
		}
		else
			std::cout << "Cannot read file" << std::endl;
	}
	int Grades::countLines(std::ifstream& fName)
	{
		std::string buf;
		int sn = 0;
		double grade = 0.0;

		int i = 0, x = 0;

		while (std::getline(fName, buf))
			i++;

		return i;
	}
}