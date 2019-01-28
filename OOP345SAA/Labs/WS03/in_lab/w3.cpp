// Workshop 3 - Templates
// w3.cpp
// Chris Szalwinski
// 2019/01/23

#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include "LVPair.h"
#include "List.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc < 2) {
		std::cerr << argv[0] << ": missing file operands\n";
		return 1;
	}
	else if (argc > 2) {
		std::cerr << argv[0] << ": too many arguments\n";
		return 2;
	}

	List<LVPair<std::string, int>, 50> ticketSales;
	std::ifstream sales(argv[1]);
	if (!sales) {
		std::cerr << "*** failed to open sales file ***\n";
		return 3;
	}
	do {
		char ticketType[50];
		int number;
		sales >> ticketType;
		if (sales) {
			sales >> number;
			sales.ignore();
			ticketSales += LVPair<std::string, int>(ticketType, number);
		}
	} while (sales);
	sales.clear();

	std::cout << "\nTicket Sales\n============\n";
	for (size_t i = 0; i < ticketSales.size(); ++i)
		std::cout << ticketSales[i];
}