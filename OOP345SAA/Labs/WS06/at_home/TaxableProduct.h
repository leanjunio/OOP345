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
		enum m_taxType { HST, PST };
		double m_taxRate;
	public:
		TaxableProduct(int productNumber, double price, char status);
		void display(std::ostream& os) const;
		iProduct* readRecord(std::ifstream& file);
		~TaxableProduct();
	};

}

#endif

