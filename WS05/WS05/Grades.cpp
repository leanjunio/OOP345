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
		if (file != nullptr || file[0] != '\0')
		{
			// BUG: grades_file ends up being null

			std::cout << file << std::endl;

			std::ifstream grades_file(file);

			if (grades_file.is_open())
			{
				m_LineCount = countLines(grades_file);
				readFile(grades_file);
			}
			else
				throw "File cannot be opened";
		}
		else
			throw "Filename is corrupted";
	}

	Grades::~Grades()
	{
		delete[] m_StudentNumbers;
		delete[] m_Grades;
	}

	// Takes a filename
	// Returns the number of lines from the file
	//
	int Grades::countLines(std::ifstream& fName)
	{
		// new lines will be skipped unless we stop it from happening:    
		fName.unsetf(std::ios_base::skipws);
		
		// count the newlines with an algorithm specialized for counting:
		unsigned line_count = std::count(std::istream_iterator<char>(fName),std::istream_iterator<char>(),'\n');

		return line_count;
	}
	
	// Takes a filename and reads its contents into the object
	//
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