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
		std::ifstream grades_file;
		std::string buffer;

		grades_file.open(file);

		if (!grades_file)
		{
			std::cerr << "Unable to open file" << std::endl;
			exit(1);
		}

		int linesinFile = countLines(grades_file);
		allocateMemory(linesinFile);
		readIntoMemory(grades_file);

		grades_file.close();
	}
	size_t Grades::countLines(std::ifstream& file)
	{
		int count = 0;;
		std::string buffer;
		while (std::getline(file, buffer))
			count++;
		return count;
	}
	void Grades::allocateMemory(size_t lines)
	{
		m_StudentNumbers = new int[lines];
		m_Grades = new double[lines];
	}
	void Grades::readIntoMemory(std::ifstream& file)
	{
		std::string buffer;
		while(std::getline(file, buffer))
			std::cout << buffer << std::endl;
	}
}