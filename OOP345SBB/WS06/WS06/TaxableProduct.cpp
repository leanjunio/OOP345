// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "TaxableProduct.h"

TaxableProduct::TaxableProduct(std::string ProductNumber, double ProductCost, char TaxCode)
	: Product(ProductNumber, ProductCost),
	m_TaxCode(TaxCode)
{
}

double TaxableProduct::getPrice() const
{
	double net = 0.0;

	if (m_TaxCode == 'H')
		net = Product::getPrice() * taxRate[0];
	if (m_TaxCode == 'P')
		net = Product::getPrice() * taxRate[1];

	return net;
}

void TaxableProduct::display(std::ostream &os) const
{
	Product::display(os);
	os << std::setw(4); 
	
	if (m_TaxCode == 'H')
		std::cout << "HST";
	else
		std::cout << "PST";
}
