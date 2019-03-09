#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
		os << std::setw(FW) << m_productNumber << std::setw(FW) << m_cost << std::endl;
	}
	iProduct * readRecord(std::ifstream & file)
	{
		iProduct* product = nullptr;
		int product_number = { 0 };
		double cost = { 0 };
		file >> product_number >> cost;
		product = new Product(product_number, cost);
		return product;
	}
	std::ostream & operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}