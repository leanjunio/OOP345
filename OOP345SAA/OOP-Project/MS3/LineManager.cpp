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
		: m_indexStartingStation(indexStartingStation)
	{
		// add the customer orders to a queue
		for (auto& i : customerOrders)
			m_ordersToFill.push(std::move(i));

		m_indexLastStation = createAssemblyOrder(indexNextStation, indexStartingStation);

		// change m_stationAddresses to be in order
		for (auto i = 0; i < stationAddresses.size(); ++i)
		{
			m_stations.push(stationAddresses[m_stationOrder[i]]);
			m_stationAddresses.push_back(stationAddresses[m_stationOrder[i]]);
		}
	}
	void LineManager::display(std::ostream& os) const
	{
		
	}

	bool LineManager::run(std::ostream& os)
	{
		// If there are items that are waiting to be filled
		while (!m_ordersToFill.empty() || m_ordersToFill.size() != 0)
		{
			// move order to the starting station - power supply in this case
			*m_stationAddresses[0] += std::move(m_ordersToFill.front());
			m_ordersToFill.pop();

			for (auto& s : m_stationAddresses)
				s->fill(os);

			size_t index = m_indexStartingStation;
			CustomerOrder temp;

			for (auto& s : m_stationAddresses)
			{
				if (s->hasAnOrderToRelease())
				{
					s->pop(temp);

					if (s != m_stationAddresses.back())
					{
						auto obj = *(&s + 1);
						std::string prev = s->getName();
						std::string next = obj->getName();
						std::string prodName = temp.getNameProduct();
						*obj += std::move(temp);
						os << " --> " << prodName << " moved from " << prev << " to " << next;
					}
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

