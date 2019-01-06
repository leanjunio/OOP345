// Workshop 3 - Templates
// w3.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"
#include "List.h"

using namespace std;

int main(int argc, char** argv)
{
	bool keepreading;

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "Inventory\n=========\n";
	List <Pair<std::string, double>, 5> inventory;

	std::string str;
	double price;

	keepreading = true;
	do {
		std::cout << "Product: ";
		getline(std::cin, str);
		if (str.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "Price: ";
			std::cin >> price;
			std::cin.ignore();
			Pair <std::string, double> pair(str, price);
			inventory += pair;
		}
	} while (keepreading);

	cout << "\nPrice List\n-----------\n";
	for (int i = 0; i < inventory.size(); i++)
		cout << inventory[i].getKey()
		<< " : " << inventory[i].getValue() << std::endl;

	std::cout << "\nGlossary\n========\n";
	List <Pair<std::string, std::string>, 5> glossary;
	std::string key, definition;

	keepreading = true;
	do {
		std::cout << "Key: ";
		getline(std::cin, key);
		if (key.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "Definition: ";
			getline(std::cin, definition);
			Pair <std::string, std::string> pair(key, definition);
			glossary += pair;
		}
	} while (keepreading);

	cout << "\nEntries\n-------\n";
	for (int i = 0; i < glossary.size(); i++)
		cout << glossary[i].getKey()
		<< " : " << glossary[i].getValue() << std::endl;

	return 0;
}