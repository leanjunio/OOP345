#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"

namespace sict
{
	class LineManager
	{
	public:
		LineManager(std::vector<Station>&, std::vector<size_t>, std::vector<CustomerOrder>, size_t, std::ostream&);
		void display(std::ostream&);
		bool run(std::ostream&);
		~LineManager();
	};
}
#endif // !SICT_LINEMANAGER_H

