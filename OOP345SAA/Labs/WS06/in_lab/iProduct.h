#ifndef _SICT_IPRODUCT_H
#define _SICT_IPRODUCT_H

#include <iostream>

namespace sict
{
	class iProduct
	{
	public:
		double price() const
		{
		}
		
		void display(std::ostream& os) const
		{
		}
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif // !_SICT_IPRODUCT_H

