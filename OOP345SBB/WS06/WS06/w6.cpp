// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	std::cout << std::fixed << std::setprecision(2);

	std::vector<w6::iProduct*> products; //A zero - size vector of pointers to iProduct objects

	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	{
		int i = 1;
		w6::iProduct* ptr_temp = nullptr;	// will contain a temporary iProduct object while processing

		//   - Print a message before starting processing a product.
		//   - Add the product to the vector "products", created above.
		//   - Handle any thrown exceptions and print the message.
		do
		{
			std::cout << "Processing record " << i << ": ";

			try
			{
				// Reads the file (only the first line) and returns either an address or nullptr
				ptr_temp = w6::readProduct(productList);
				
				if (ptr_temp)
				{
					products.push_back(ptr_temp);
					std::cout << "done!" << std::endl;
				}
				else
					std::cout << "no such record! Reached the end of the file!" << std::endl;
			}
			catch (std::string err)
			{
				std::cout << err << std::endl;
			}
			i++;
		} while (ptr_temp != nullptr);
	}
	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

	double total = 0.0;
	std::cout << "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
	for (auto i = 0u; i < products.size(); i++) {
		total += products[i]->getPrice();
		std::cout << *products[i];
	}
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) << "Total: ";
	std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";

	return 0;
}