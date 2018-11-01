#ifndef _TAXABLE_PRODUCT_H

#include <string>
#include "Product.h"

class TaxableProduct : public Product
	// Derives from Product and holds additional information about the product's taxable status
{
	char m_TaxCode;
public:
	TaxableProduct(std::string ProductNumber, double ProductCost, char TaxCode);
	~TaxableProduct();
};

#endif // !_TAXABLE_PRODUCT_H


