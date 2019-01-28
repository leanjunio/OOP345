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
	if (argc <= 2) {
		std::cerr << argv[0] << ": missing file operands\n";
		return 1;
	}
	else if (argc > 3) {
		std::cerr << argv[0] << ": too many arguments\n";
		return 2;
	}

	// TODO: create a list of summable LVPairs named references
	// each LVPair consists of a label of type std::string and a value of type std::string
	// the maximum number of elements in the list is 50
	//
	std::ifstream index(argv[1]);
	if (!index) {
		std::cerr << "*** failed to open index file ***\n";
		return 3;
	}
	do {
		char label[50], reference[50];
		index >> label;
		if (index) {
			index >> reference;
			index.ignore();
			// TODO: create a temporary SummableLVPair from ticketType and number
			// add the tempoary object to the references list
			//
			references +=
		}
	} while (index);
	index.clear();

	std::cout << "\nIndividual Index Entries\n========================\n";
	for (size_t i = 0; i < references.size(); ++i)
		std::cout << references[i];
	std::cout << "\nCollated Index Entries\n======================\n";
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Pointers  " << references.accumulate("Pointers") << std::endl;
	std::cout << "References" << references.accumulate("References") << std::endl;

	const double studentFare = 2.05;
	double adultFare = 3.25;
	// TODO: create a list of summable LVPairs named ticketSales
	// each LVPair consists of a label of type std::string and a value of type int
	// the maximum number of elements in the list is 50
	//
	std::ifstream sales(argv[2]);
	if (!sales) {
		std::cerr << "*** failed to open sales file ***\n";
		return 4;
	}
	do {
		char ticketType[50];
		int number;
		sales >> ticketType;
		if (sales) {
			sales >> number;
			sales.ignore();
			// TODO: create a temporary SummableLVPair from ticketType and number
			// add the tempoary object to the ticketSales list
			//
			ticketSales +=
		}
	} while (sales);
	sales.clear();

	std::cout << "\nDetail Ticket Sales\n===================\n";
	for (size_t i = 0; i < ticketSales.size(); ++i)
		std::cout << ticketSales[i];
	std::cout << "\nSummary of Ticket Sales\n=======================\n";
	std::cout << std::fixed << std::setprecision(2) << std::right;
	std::cout << "Student Tickets = " << std::setw(7) << ticketSales.accumulate("Student") * studentFare << std::endl;
	std::cout << "Adult Tickets   = " << std::setw(7) << ticketSales.accumulate("Adult") * adultFare << std::endl;
}