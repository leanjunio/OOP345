// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
	class iProduct
	{
	public:
		virtual double getPrice() const = 0;
		virtual void display(std::ostream&) const = 0;
	};
}
#endif