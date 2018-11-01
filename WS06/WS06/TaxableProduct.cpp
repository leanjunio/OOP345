#include "TaxableProduct.h"

TaxableProduct::TaxableProduct(std::string ProductNumber, double ProductCost, char TaxCode)
	: Product(ProductNumber, ProductCost),
	m_TaxCode(TaxCode)
{
}

TaxableProduct::~TaxableProduct()
{
}
