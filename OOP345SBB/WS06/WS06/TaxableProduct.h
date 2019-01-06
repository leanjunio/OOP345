// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// TaxableProduct.h

#ifndef _TAXABLE_PRODUCT_H

#include <string>
#include <array>
#include "Product.h"

// Derives from Product and holds additional information about the product's taxable status
//
class TaxableProduct : public Product
{
	std::array<float, 2> taxRate = { 1.13, 1.08 };
	char m_TaxCode;
public:
	TaxableProduct(std::string ProductNumber, double ProductCost, char TaxCode);

	double getPrice() const;
	void display(std::ostream&) const;
};

#endif // !_TAXABLE_PRODUCT_H


