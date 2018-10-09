// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <string>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	Grades grades(argv[1]);

	auto letter = [](float grade)
	{
		// TODO: Find a way to get the grades from the file
		std::string letterGrade;
		if (grade >= 90 && grade <= 100)
			letterGrade = "A+";
		else if (grade >= 80 && grade <= 89)
			letterGrade = "A";
		else if (grade >= 75 && grade <= 79)
			letterGrade = "B+";
		else if (grade >= 70 && grade <= 74)
			letterGrade = "B";
		else if (grade >= 65 && grade <= 69)
			letterGrade = "C+";
		else if (grade >= 60 && grade <= 64)
			letterGrade = "C";
		else if (grade >= 55 && grade <= 59)
			letterGrade = "D+";
		else if (grade >= 50 && grade <= 54)
			letterGrade = "D";
		else if (grade >= 0 && grade <= 49)
			letterGrade = "F";

		return letterGrade;
	};

	//grades.displayGrades(std::cout, letter);

	return 0;
}