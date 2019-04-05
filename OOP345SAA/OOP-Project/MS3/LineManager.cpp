#include <algorithm>
#include <vector>
#include "Station.h"
#include "LineManager.h"

namespace sict
{
	// moves the customer orders to the front of a queue in which orders are waiting to be filled
	// determines the index of the last station on the line
	//
	LineManager::LineManager(std::vector<Station*>& stationAddresses, std::vector<size_t>& indexNextStation, std::vector<CustomerOrder>& customerOrders, size_t indexStartingStation, std::ostream& os)
		: m_stationAddresses{ stationAddresses }
		, m_indexStartingStation(indexStartingStation)
	{
		for (auto& i : customerOrders)
			m_ordersToFill.push(std::move(i));

		m_indexLastStation = createAssemblyOrder(indexNextStation, indexStartingStation);
	}
	void LineManager::display(std::ostream& os) const
	{
		
	}

	bool LineManager::run(std::ostream& os)
	{
		// If there are items that are waiting to be filled
		while (!m_ordersToFill.empty())
		{
			// move the items to the starting station on the line then remove the transferred element from the queue
			*(m_stationAddresses[m_indexStartingStation]) += std::move(m_ordersToFill.front());
			m_ordersToFill.pop();

			// Fill each station's orders
			for (auto& s : m_stationAddresses)
				s->fill(os);

			for (auto& s : m_stationAddresses)
			{
				if (s->hasAnOrderToRelease())
				{

				}
			}
		}

		return false;
	}

	// PRIVATE MEMBERS

	/**
	 * Updates the m_stationOrder vector to contain the order that the stations will be processsed to
	 * returns the index of the last station
	*/
	size_t LineManager::createAssemblyOrder(std::vector<size_t>& indexNextStation, size_t indexStartingStation)
	{
		m_stationOrder.push_back(indexStartingStation);

		for (auto i = 0; i < indexNextStation.size(); ++i)
		{
			m_stationOrder.push_back(indexNextStation[indexStartingStation]);
			indexStartingStation = indexNextStation[indexStartingStation];
		}

		return m_stationOrder.front();
	}
}

