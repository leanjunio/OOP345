#pragma once

#include <vector>
#include <queue>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict
{
	/**
	 * Contains all the functionality for processing customer orders across the entire assembly line
	 * The LineManager moves orders along the assemblyLine one step at a time
	 */
	class LineManager
	{
		std::vector<Station*> m_stationAddresses;
		std::queue<Station*> m_stations;
		std::queue<CustomerOrder> m_ordersToFill;
		std::vector<size_t> m_indexNextStation;
		std::vector<CustomerOrder> m_ordersCompleted;
		size_t m_indexStartingStation;
		std::vector<size_t> m_stationOrder;
	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream&) const;
		bool run(std::ostream&);
	};
}


