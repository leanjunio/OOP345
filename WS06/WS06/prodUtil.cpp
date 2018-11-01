// prodUtil.cpp

#include <iostream>
#include <fstream>
#include "ProdUtil.h"
#include "iProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream& os, const iProduct& product)
	{
		os << product;
		return os;
	}

	iProduct* readProduct(std::ifstream& file)
	{
		iProduct* temp;
		return temp;
	}
}