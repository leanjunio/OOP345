#ifndef _SICT_SALE_H
#define _SICT_SALE_H

#include <vector>
#include "Product.h"

namespace sict
{
	class Sale
	{
		std::vector<iProduct*> m_products;
	public:
		explicit Sale(const char*);
		void display(std::ostream& os) const;
	};
}

#endif // !_SICT_SALE_H

