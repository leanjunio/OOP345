#pragma once

#include <vector>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict
{
	class LineManager
	{
	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream&) const;
		bool run(std::ostream&);
	};
}


