// prodUtil.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ProdUtil.h"
#include "TaxableProduct.h"
#include "iProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream& os, const iProduct& product)
	{
		os << product;
		return os;
	}

	iProduct* readProduct(std::ifstream& file)
	{
		iProduct* ptr = nullptr;
		double ProductCost;
		char tax = {};
		std::string buffer, ProductNumber;

		// NOTE: if file read has an error, the value of ptr should not change from nullptr
		if (file.good())
		{
			while (std::getline(file, buffer, '\n'))
			{
				std::stringstream iss(buffer);

				if (buffer.length() == 11)
				{
					iss >> ProductNumber >> ProductCost;
					ptr = new Product(ProductNumber, ProductCost);
				}

				// Saves tax and check if it is valid
				if (buffer.length() == 13)
				{
					iss >> ProductNumber >> ProductCost >> tax;

					std::cout << "tax: " << tax << std::endl;
					bool valid_tax = tax == 'H' || tax == 'P';
					
					if (!valid_tax)
						tax = 0;

					ptr = new TaxableProduct(ProductNumber, ProductCost, tax);
				}
			}
		}

		return ptr;
	}
}