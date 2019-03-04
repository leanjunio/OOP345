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
	Product::~Product()
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
}

