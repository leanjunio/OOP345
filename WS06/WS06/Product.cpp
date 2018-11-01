#include <string>
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
	/*
		a query that receives a reference to the output stream and inserts the product information in the form of a single line into the output stream.
		The product code and price should be printed on fields of width 16 characters.
	*/
}
