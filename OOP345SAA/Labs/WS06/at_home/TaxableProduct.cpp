#include <iostream>
#include <string>
#include <fstream>
#include "TaxableProduct.h"

namespace sict
{
	TaxableProduct::TaxableProduct(int productNumber, double price, Tax type)
		: Product(productNumber, price)
	{
		if (type == Tax::HST)
			m_taxRate = 0.13;
		else if (type == Tax::PST)
			m_taxRate = 0.08;
		else
			throw(std::string("Invalid Tax Type Found."));
	}

	double TaxableProduct::price() const
	{
		return Product::price() * (1 + m_taxRate);
	}

	void TaxableProduct::display(std::ostream & os) const
	{
		Product::display(os);
		os << (m_taxRate == 0.13) ? " HST" : " PST";
	}

	iProduct * TaxableProduct::readRecord(std::ifstream & file)
	{
		return nullptr;
	}
}
