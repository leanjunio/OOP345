// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Product.h

#ifndef _PRODUCT_H

#include <iostream>
#include <string>
#include "iProduct.h"

class Product : public w6::iProduct
	// Holds information about a product that consists of its product number and its cost
{
	 std::string m_ProductNumber;
	double m_ProductCost;
public:
	Product();
	Product(std::string& ProductNumber, double ProductCost);
	~Product();

	double getPrice() const;
	void display(std::ostream& os) const;
};

#endif // !_PRODUCT_H

