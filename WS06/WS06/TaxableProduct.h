#ifndef _TAXABLE_PRODUCT_H
#include "Product.h"

class TaxableProduct : public Product
	// Derives from Product and holds additional information about the product's taxable status
{
	char m_TaxCode;
public:
	TaxableProduct();
	~TaxableProduct();
};

#endif // !_TAXABLE_PRODUCT_H


