// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

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
		product.display(os);
		os << std::endl;
		return os;
	}

	iProduct* readProduct(std::ifstream& file)
	{
		iProduct* ptr = nullptr;
		double ProductCost = {};
		char tax = {};
		std::string buffer, ProductNumber;

		// NOTE: if file read has an error, the value of ptr should not change from nullptr
		if (file.good())
		{
			// Working one line at a time...
			if (std::getline(file, buffer, '\n'))
			{
				std::stringstream iss(buffer);

				// If the length is 11, there's no letter for tax
				if (buffer.length() == 11)
				{
					iss >> ProductNumber >> ProductCost;
					ptr = new Product(ProductNumber, ProductCost);
				}

				// If the length is 13, letter for tax exists
				if (buffer.length() == 13)
				{
					iss >> ProductNumber >> ProductCost >> tax;
					bool valid_tax = tax == 'H' || tax == 'P';
					if (valid_tax)
						ptr = new TaxableProduct(ProductNumber, ProductCost, tax);
					else
					{
						std::string err = "Unrecognizable Tax Code!";
						tax = 0;
						throw err;
					}
				}
			}
		}

		return ptr;
	}
}