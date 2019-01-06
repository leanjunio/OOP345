// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

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
