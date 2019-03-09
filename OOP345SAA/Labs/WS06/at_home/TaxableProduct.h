#ifndef _SICT_TAXABLE_PRODUCT_H
#define _SICT_TAXABLE_PRODUCT_H

#include <iostream>
#include <fstream>
#include "Product.h"

namespace sict
{
	class TaxableProduct :
		public Product
	{
		enum class Tax: char { HST = 'H', PST = 'P' };
		double m_taxRate;
	public:
		TaxableProduct(int, double, Tax);
		double price() const;
		void display(std::ostream&) const;
		iProduct* readRecord(std::ifstream&);
	};

}

#endif

