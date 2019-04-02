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
		// Constructor that moves the customer orders to the front of a queue holding the orders waiting to be filled
		// Determines the index of the last station on the line
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream&);
		bool run(std::ostream&);
		~LineManager();
	};
}
#endif // !SICT_LINEMANAGER_H

