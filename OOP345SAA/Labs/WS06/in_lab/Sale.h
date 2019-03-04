#ifndef _SICT_SALE_H
#define _SICT_SALE_H

#include <vector>
#include "Product.h"

namespace sict
{
	class Sale
	{
		std::vector<Product*> products;
	public:
		explicit Sale(const char*);
		void display(std::ostream& os) const;
		~Sale();
	};
}

#endif // !_SICT_SALE_H

