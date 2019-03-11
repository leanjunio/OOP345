#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "TaxableProduct.h"
#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product()
		: m_productNumber{0}
		, m_cost{0.0}
	{
	}
	Product::Product(int productNumber, double cost)
		: m_productNumber{productNumber}
		, m_cost{cost}
	{
	}
	double Product::price() const
	{
		return m_cost;
	}
	void Product::display(std::ostream & os) const
	{
		os << std::setw(FW) << m_productNumber << std::setw(FW) << m_cost;
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
	std::ostream & operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}