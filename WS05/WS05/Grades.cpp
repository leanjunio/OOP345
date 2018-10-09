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
			m_LineCount = countLines(grades_file);
			readFile(grades_file);
		}
		else
			std::cout << "Cannot read file" << std::endl;
	}
	int Grades::countLines(std::ifstream& fName)
	{
		std::string buf;
		int i = 0;

		while (std::getline(fName, buf))
			i++;

		return i;
	}
	void Grades::readFile(std::ifstream & fName)
	{
		int sn = 0, i = 0; double grade = 0.0;
		std::string buf;
		fName.clear();
		fName.seekg(0, std::ios::beg);
		
		// Allocation
		m_StudentNumbers = new int[m_LineCount];
		m_Grades = new double[m_LineCount];

		while (fName >> sn >> grade)
		{
			m_StudentNumbers[i] = sn;
			m_Grades[i] = grade;
			i++;
		}
	}
}