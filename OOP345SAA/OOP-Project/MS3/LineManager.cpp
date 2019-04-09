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
		: m_stationAddresses{stationAddresses}
		, m_indexStartingStation{ indexStartingStation }
	{
		for (auto& customerOrder : customerOrders)
			m_ordersToFill.push_back(std::move(customerOrder));

		m_indexLastStation = createAssemblyOrder(indexNextStation, indexStartingStation);

		m_indexNextStation = indexNextStation;
		m_orderSize = m_ordersToFill.size();
	}
	void LineManager::display(std::ostream& os) const
	{
		os << "COMPLETED ORDERS" << std::endl;
		for (auto& i : m_complete)
			i.display(os, true); 
		os << std::endl;

		os << "INCOMPLETE ORDERS" << std::endl;
		for (auto& i : m_incomplete) 
			i.display(os, true); 
	}

	bool LineManager::run(std::ostream& os)
	{
		bool done = false;
		CustomerOrder temp;
		
		// move order at the front into m_stationAddresses
		if (!m_ordersToFill.empty())
		{
			// assign order at front of pending to the first station's customerOrders
			// delete the order that was assigned from the pending list
			*m_stationAddresses[m_indexStartingStation] += std::move(m_ordersToFill.front());
			m_ordersToFill.pop_front();
		}

		// fill the order that is at the front of each order...i.e Elliot - Power Supply
		try
		{
			// BUG: Since only the "Power Supply" station is filled at this point, whenever other stations are attempted to be filled, an error will be found
			// FACT CHECK: All orders are currently in station 1...
			// TODO: Fill the order that's at the front of the station
			for (size_t i = 0; i != m_indexNextStation.size(); ++i)
				m_stationAddresses[i]->fill(os);

			// if the current station has an order to release, release it.
			for (size_t i = 0; i < m_stationAddresses.size(); ++i)
			{
				bool hasOrderForRelease = m_stationAddresses[i]->hasAnOrderToRelease();
				bool isTheLastStation = m_indexNextStation[i] == m_indexLastStation;

				if (hasOrderForRelease && isTheLastStation)
				{
					m_stationAddresses[i]->pop(temp);

					if (temp.isFilled())
					{
						os << " --> " << temp.getNameProduct() << " moved from " << m_stationAddresses[i]->getName() << " to Completed Set" << std::endl;
						m_complete.push_back(std::move(temp));
						m_orderSize--;
					}
					else
					{
						os << " --> " << temp.getNameProduct() << " moved from " << m_stationAddresses[i]->getName() << " to Incompleted Set" << std::endl;
						m_incomplete.push_back(std::move(temp));
						m_orderSize--;
					}
				}
				if (hasOrderForRelease && !isTheLastStation)
				{
					// release the order at the front
					m_stationAddresses[i]->pop(temp);
					os << " --> " << temp.getNameProduct() << " moved from " << m_stationAddresses[i]->getName() << " to " << m_stationAddresses[m_indexNextStation[i]]->getName() << std::endl;

					*m_stationAddresses[m_indexNextStation[i]] += std::move(temp);
				}
			}
			
		}
		catch (const std::exception& e)
		{
			e.what();
		}

		if (m_orderSize == 0)
			done = true;
		else
			done = false;

		return done;
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

		return m_stationOrder.back();
	}
}

