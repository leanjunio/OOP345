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