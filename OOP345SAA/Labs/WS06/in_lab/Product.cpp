#include <iostream>
#include <fstream>
#include <string>
#include "Product.h"

namespace sict
{
	Product::Product()
		: m_cost{0.0}
		, m_productNumber{0}
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
		os << m_productNumber << " " << m_cost << std::endl;
	}
	iProduct * readRecord(std::ifstream & file)
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			size_t space_pos = buffer.find(' ');
			int product_number = std::stoi(buffer.substr(0, space_pos));
			double cost = std::stod(buffer.substr(space_pos));      

			Product *p = new Product(product_number, cost);
			return p;
		}
	}
	std::ostream & operator<<(std::ostream & os, const iProduct & p)
	{
		p.display(os);
		return os;
	}
}

