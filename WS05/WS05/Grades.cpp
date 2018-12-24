// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca 
// Date of completion: 10/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <string>
#include <algorithm>
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
	Grades::Grades(const char* grades)
	{	
		// Initialize resources
		m_Grades = nullptr;
		m_StudentNumbers = nullptr;

		std::ifstream file {grades};

		if (!file)
			throw "File cannot be read";

		m_LineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
		readLines(file);
	}

	// Deallocates the resources used earlier in the program's runtime
	//
	Grades::~Grades()
	{
		delete[] m_StudentNumbers;
		delete[] m_Grades;
	}

	// Reads the file for records and stores them in the class
	// Allocates memory for Grades and StudentNumbers depending on the size of the file's \n characters
	//
	void Grades::readLines(std::ifstream& file)
	{
		// Dynamically allocate grades and studentNumbers
		m_Grades = new double[m_LineCount];
		m_StudentNumbers = new int[m_LineCount];

		if (file.is_open())
		{
			file.clear();
			file.seekg(0, std::ios::beg);

			int sn = 0, i = 0; double grade = 0.0;

			while (i < m_LineCount && file >> sn >> grade)
			{
				m_StudentNumbers[i] = sn;
				m_Grades[i] = grade;
				++i;
			}

			file.close();
		}
	}
}