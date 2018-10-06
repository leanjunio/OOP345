// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <string>
#include "Grades.h"

namespace sict
{
	Grades::Grades()
		: ptr_StudentNumbers(nullptr)
		, ptr_StudentGrades(nullptr)
		, recordCounter(0)
	{
	}
	Grades::Grades(const char* filename)
		// Read the file
	{
		if (filename[0] != '\0')
		{
			std::ifstream file(filename);
			
			if (file.is_open())
			{
				std::string line;
				counter(file);
				readFile(file);
			}
		}
	}

	void Grades::counter(std::ifstream& file)
	{
		std::string buf;
		int num = 0;
		while(std::getline(file, buf))
			num++;

		recordCounter = num;
	}

	void Grades::readFile(std::ifstream& file)
		// reads the contents of the file into the members
	{
		int i = 0, sn;
		double grade;
		std::string buf;

		// set allocated address
		ptr_StudentNumbers = new int[recordCounter];
		ptr_StudentGrades = new double[recordCounter];

		if (file.is_open())
		{
			while(std::getline(file >> sn >> grade))
			{
				ptr_StudentGrades[i] = grade;
				ptr_StudentNumbers[i] = sn;
				i++;
			}
		}

		// test
		
		for(size_t i = 0; i < recordCounter; i++)
		{
			std::cout << ptr_StudentNumbers[i] << std::endl;
		}
		
	}
}