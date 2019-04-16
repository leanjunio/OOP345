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
		
		if (!m_ordersToFill.empty())
		{
			*m_stationAddresses[m_indexStartingStation] += std::move(m_ordersToFill.front());
			m_ordersToFill.pop_front();
		}

		try
		{
			for (size_t i = 0; i != m_indexNextStation.size(); ++i)
				m_stationAddresses[i]->fill(os);

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

		for (size_t i = 0; i < indexNextStation.size(); ++i)
		{
			m_stationOrder.push_back(indexNextStation[indexStartingStation]);
			indexStartingStation = indexNextStation[indexStartingStation];
		}

		return m_stationOrder.back();
	}
}

