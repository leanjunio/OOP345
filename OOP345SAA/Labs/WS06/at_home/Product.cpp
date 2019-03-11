#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Product.h"
// #include "TaxableProduct.h"

extern int FW;

namespace sict
{
	/**
	 * Product Module
	*/
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

	/**
	 * Taxable Product Module
	 * 
	*/
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

	/**
	 * Helper Modules
	*/
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