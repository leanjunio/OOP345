// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <string>
#include <typeinfo>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) 
{

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) 
	{
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) 
	{
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	try
	{
		sict::Grades grades(argv[1]);

		auto letter = [](float grade)
		{
			if (grade >= 90 && grade <= 100)
				return Letter::Aplus;
			else if (grade >= 80 && grade <= 89.9)
				return Letter::A;
			else if (grade >= 75 && grade <= 79.9)
				return Letter::Bplus;
			else if (grade >= 70 && grade <= 74.9)
				return Letter::B;
			else if (grade >= 65 && grade <= 69.9)
				return Letter::Cplus;
			else if (grade >= 60 && grade <= 64.9)
				return Letter::C;
			else if (grade >= 55 && grade <= 59.9)
				return Letter::Dplus;
			else if (grade >= 50 && grade <= 54.9)
				return Letter::D;
			else if (grade >= 0 && grade <= 49.9)
				return Letter::F;
			else
				throw "Not a grade";
		};

		grades.displayGrades(std::cout, letter);
	}
	catch (const std::string& message)
	{
		std::cout << message << std::endl;
	}
	
		return 0;
}