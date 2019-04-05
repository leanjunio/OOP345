#include <algorithm>
#include <vector>
#include "LineManager.h"

namespace sict
{
	// moves the customer orders to the front of a queue in which orders are waiting to be filled
	// determines the index of the last station on the line
	//
	LineManager::LineManager(std::vector<Station*>& stationAddresses, std::vector<size_t>& indexNextStation, std::vector<CustomerOrder>& customerOrders, size_t indexStartingStation, std::ostream& os)
		: m_indexStartingStation(indexStartingStation)
	{
		// add all the stationAddresses into the queue
		for (auto&& i : stationAddresses)
			m_stations.push(i);

		//for (auto&& i : stationAddresses)


		// add all the customerOrders to be filled into the ordersToFill queue
		for (auto& i : customerOrders)
			m_ordersToFill.push(std::move(i));

		// copy the next station indexes
		m_indexNextStation.assign(indexNextStation.begin(), indexNextStation.end());

		// create the assembly line order
		m_stationOrder.push_back(indexStartingStation);

		// copy stationAddresses
		for (auto&& i : stationAddresses)
			m_stationAddresses.push_back(std::move(i));
	}
	void LineManager::display(std::ostream& os) const
	{
		if (!m_ordersToFill.empty())
		{
			
		}
	}

	bool LineManager::run(std::ostream& os)
	{
		// if there's a customer order on the back of the queue waiting to be filled this function 
		if (!m_ordersToFill.empty())
		{
			// moves the customer order to the starting station on the line
			*m_stationAddresses[m_indexStartingStation] += std::move(m_ordersToFill.front());

			// executes one fill step of the assembly process at each station on the line
			
			
			
			return true;
		}
		else
			return false;
	}
}
