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
		std::queue<CustomerOrder> m_complete;
		std::queue<CustomerOrder> m_incomplete;
		std::queue<CustomerOrder> m_ordersToFill;
		std::vector<size_t> m_indexNextStation;
		size_t m_indexStartingStation;
		size_t m_indexLastStation;
		std::vector<size_t> m_stationOrder;
	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream&) const;
		bool run(std::ostream&);
	private:
		size_t createAssemblyOrder(std::vector<size_t>&, size_t);
	};
}


