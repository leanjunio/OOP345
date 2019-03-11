#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "TaxableProduct.h"

extern int FW;

namespace sict
{
	// 3-argument constructor that creates the object - TaxableProduct contains a Product
	//
	TaxableProduct::TaxableProduct(int productNumber, double price, char status)
		: Product(productNumber, price)
		, m_taxRate(status == 'H' ? 0.13 : 0.08)
	{
	}

	// Returns the price with tax (net price) of the product
	//
	double TaxableProduct::price() const
	{
		return Product::price() * (1 + m_taxRate);
	}

	// Displays the information about the product with tax status
	//
	void TaxableProduct::display(std::ostream & os) const
	{
		Product::display(os);

		if (m_taxRate == 0.13)
			os << " HST";
		else
			os << " PST";
	}

	iProduct* readRecord(std::ifstream & file)
	{
		iProduct* product = nullptr;

		std::string line = {};
		int product_number = { 0 };
		double price = { 0 };
		char tax = { '\0' };
		
		while (std::getline(file, line, '\n'))
		{
			size_t count = std::count(line.begin(), line.end(), ' ');		// count how many spaces in line
			std::stringstream stream(line);
			if (count == 2)
			{
				stream >> product_number >> price >> tax;
				product = new TaxableProduct(product_number, price, tax);
				break;
			}
			else
			{
				stream >> product_number >> price;
				product = new Product(product_number, price);
				break;
			}
		}

		return product;
	}
}
