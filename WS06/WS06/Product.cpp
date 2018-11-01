#include <string>
#include <iomanip>
#include "Product.h"

Product::Product()
	: m_ProductNumber{},
	m_ProductCost{}
{
}

Product::Product(std::string & ProductNumber, double ProductCost)
	: m_ProductNumber{ProductNumber},
	m_ProductCost{ProductCost}
{
}

Product::~Product()
{
}

double Product::getPrice() const
{
	return m_ProductCost;
}

void Product::display(std::ostream & os) const
{
	os << std::setw(16) << m_ProductNumber << std::setw(16) << m_ProductCost;
}
