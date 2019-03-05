#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H

#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		int m_productNumber;
		double m_cost;
	public:
		Product();
		explicit Product(int, double);
		double price() const override;
		void display(std::ostream& os) const override;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);	
}
#endif // !_SICT_PRODUCT_H