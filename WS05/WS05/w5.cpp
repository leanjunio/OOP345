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

	auto letter = [](double grade) -> const char*
	{
		std::string letterGrade;

		if (grade >= 90 && grade <= 100)
			return convert(Letter::Aplus);
		else if (grade >= 80 && grade <= 89)
			return convert(Letter::A);
		else if (grade >= 75 && grade <= 79)
			return convert(Letter::Bplus);
		else if (grade >= 70 && grade <= 74)
			return convert(Letter::B);
		else if (grade >= 65 && grade <= 69)
			return convert(Letter::Cplus);
		else if (grade >= 60 && grade <= 64)
			return convert(Letter::C);
		else if (grade >= 55 && grade <= 59)
			return convert(Letter::Dplus);
		else if (grade >= 50 && grade <= 54)
			return convert(Letter::D);
		else if (grade >= 0 && grade <= 49)
			return convert(Letter::F);
	};

	grades.displayGrades(std::cout, letter);

	return 0;
}