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

	//TODO: Update the main functions as per the specifications here
	Grades grades(argv[1]);

	// TODO: use the template function defined in letter.h
	// auto letter = []()
	// {
	// 	// TODO: Find a way to get the grades from the file
	// 	if (grade >= 90 && grade <= 100)
	// 		return "A+";
	// 	if (grade >= 80 && grade <= 89)
	// 		return "A";
	// 	if (grade >= 75 && grade <= 79)
	// 		return "B+";
	// 	if (grade >= 70 && grade <= 74)
	// 		return "B";
	// 	if (grade >= 65 && grade <= 69)
	// 		return "C+";
	// 	if (grade >= 60 && grade <= 64)
	// 		return "C";
	// 	if (grade >= 55 && grade <= 59)
	// 		return "D+";
	// 	if (grade >= 50 && grade <= 54)
	// 		return "D";
	// 	if (grade >= 0 && grade <= 49)
	// 		return "F";
	// };

	// grades.displayGrades(std::cout, letter);

	return 0;
}