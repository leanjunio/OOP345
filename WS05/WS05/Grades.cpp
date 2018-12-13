// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca 
// Date of completion: 10/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>
#include <functional>
#include <iostream>
#include "Grades.h"

namespace sict
{
	// A constructor that accepts a filename as a parameter
	// Check if the filename is legitemate and throw an error if not
	//
	Grades::Grades(const char* file)
	{	
		// Check if the file name is correct
		if (file != nullptr && file[0] != '\0')
		{
			std::ifstream gradesFile(file, std::ios::binary);

			if (gradesFile.is_open())
			{
				// new lines will be skipped unless we stop it from happening:    
				gradesFile.unsetf(std::ios_base::skipws);

				// count the newlines with an algorithm specialized for counting:
				unsigned line_count = std::count(std::istream_iterator<char>(gradesFile), std::istream_iterator<char>(), '\n');
				gradesFile.clear();
				gradesFile.seekg(0, std::ios::beg);

				int sn = 0, i = 0; double grade = 0.0;
				std::string buf;

				m_StudentNumbers = new int[line_count];
				m_Grades = new double[line_count];

				// At this point: gradesFile is NULL
				while (gradesFile >> sn >> grade)
				{
					m_StudentNumbers[i] = sn;
					m_Grades[i] = grade;
					i++;
				}
			}
		}
		else
			throw "Filename is corrupted";
	}

	Grades::~Grades()
	{
		delete[] m_StudentNumbers;
		delete[] m_Grades;
	}

	void Grades::readFile(std::ifstream & fName)
	{
		int sn = 0, i = 0; double grade = 0.0;
		std::string buf;
		fName.clear();
		fName.seekg(0, std::ios::beg);
		
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