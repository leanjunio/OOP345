#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <queue>
#include <iostream>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict
{
	class Station
	{
		std::queue<CustomerOrder> m_customerOrders;
		ItemSet m_set;
	public:
		Station(const std::string&);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;
		Station();
		~Station();

		void display(std::ostream&) const;
		void fill(std::ostream&);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder&);
		void validate(std::ostream&);
	};
}

#endif // !SICT_STATION_H


