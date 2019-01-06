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
#include "Product.h"

class TaxableProduct : public Product
{
	char m_TaxCode;
public:
	TaxableProduct();
	TaxableProduct(std::string ProductNumber, double ProductCost, char TaxCode);
	~TaxableProduct();

	double getPrice() const;
	void display(std::ostream&) const;
};

#endif // !_TAXABLE_PRODUCT_H


