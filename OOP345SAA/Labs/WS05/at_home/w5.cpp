// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <exception>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	try
	{
		// check for command line errors
		if (argc != 3) 
			exit(1);

		// set for fixed, 2-decimal point output
		std::cout << std::fixed << std::setprecision(2);

		// process price list file
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));

		// grade list file
		KVList<KVPair<int, float>> gradeList = createList<
			KVList<KVPair<int, float>>,
			KVPair<int, float>,
			int,
			float>
			(argv[2]);
		std::cout << "\nStudent List Letter Grades Included\n==================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		gradeList.display(std::cout, [](float grade) -> std::string
		{
			if (grade >= 90 && grade <= 100)
				return "A+";
			else if (grade >= 80 && grade <= 89.9)
				return "A ";
			else if (grade >= 75 && grade <= 79.9)
				return "B+";
			else if (grade >= 70 && grade <= 74.9)
				return "B ";
			else if (grade >= 65 && grade <= 69.9)
				return "C+";
			else if (grade >= 60 && grade <= 64.9)
				return "C ";
			else if (grade >= 55 && grade <= 59.9)
				return "D+";
			else if (grade >= 50 && grade <= 54.9)
				return "D ";
			else if (grade >= 0 && grade <= 49.9)
				return "F ";
			else
				throw "Not a grade";
		});
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Caught exception: " << ex.what() << std::endl;
		exit(2);
	}
}