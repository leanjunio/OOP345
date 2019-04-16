#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <queue>
#include <iostream>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict
{
	/**
	 * Contains all the functionality for filling customer orders with items.
	 * NOTE: Each station that has an order can fill one request at a time for an ITEM from that station (each station has one item)
	 * An order can be incomplete due to insufficient items in stock to cover its requests
	*/
	class Station
	{
		std::deque<CustomerOrder> m_stationCustomerOrders;
		std::string m_stationName;
		ItemSet m_stationInventory;
	public:
		explicit Station(const std::string&);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;

		void display(std::ostream&) const;
		void fill(std::ostream&);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};
}

#endif // !SICT_STATION_H


