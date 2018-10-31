// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}
#endif