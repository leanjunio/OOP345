// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Author:  Dr. Elliott Coleshill
// Date:    2018-08-31
// Updated by Cornel -- Changed the timing to nanoseconds and changed namespace

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include "Text.h"
#define TIMEP(start, end) (std::chrono::duration_cast<std::chrono::nanoseconds>((end) - (begin)).count())

int main(int argc, char* argv[])
{
	std::ofstream ofs("Lab2Output.txt");

	if (argc == 1)
	{
		std::cout << argv[0] << ": missing file operand\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cout << argv[0] << ": too many arguments\n";
		return 2;
	}

	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	{
		begin = std::chrono::high_resolution_clock::now();
		w2::Text a;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Default Constructor "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		w2::Text b(argv[1]);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Custom Constructor  "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - b.size = " << b.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		a = b;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Copy Assignment     "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		a = std::move(b);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Move Assignment     "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		w2::Text c = a;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Copy Constructor    "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - c.size = " << c.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		w2::Text d = std::move(a);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Move Constructor    "
			<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
			<< " - d.size = " << d.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
	}
	end = std::chrono::high_resolution_clock::now();
	ofs << "Destructor          "
		<< std::setw(10) << TIMEP(begin, end) << " nanoseconds"
		<< std::endl;

	ofs.close();
	return 0;
}