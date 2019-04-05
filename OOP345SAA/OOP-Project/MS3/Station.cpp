#include "Station.h"
#include "ItemSet.h"

namespace sict
{
	// Receives a reference to an unmodifiable string and passes that reference to the ItemSet sub-object of the current object
	//
	Station::Station(const std::string& string)
		: m_stationInventory(string)
	{
	}

	// displays data for the ItemSet object on os
	//
	void Station::display(std::ostream& os) const
	{
		m_stationInventory.display(os, true);
	}

	// fills the last order in the customer order queue (if there is one), if the queue is empty, the function does nothing
	//
	void Station::fill(std::ostream& os)
	{
		if (!m_stationCustomerOrders.empty())
			m_stationCustomerOrders.back().fillItem(m_stationInventory, os);
	}

	// returns a reference to the name of the ItemSet sub-object
	//
	const std::string& Station::getName() const
	{
		return m_stationInventory.getName();
	}

	// Returns the release state of the current object
	// Return true if the station has filled item requests for the customer order at the front of the queue or the station has no items left
	//
	bool Station::hasAnOrderToRelease() const
	{
		// check if the customerOrder at front of queue is filled check if the station has no items left
		bool hasAnOrderToRelease = (m_stationCustomerOrders.front().isFilled() || m_stationInventory.getQuantity() == 0) && !m_stationCustomerOrders.empty();
		return hasAnOrderToRelease;

	}
	Station& Station::operator--()
	{
		--m_stationInventory;
		return *this;
	}

	// (Modifier) - Receives an rvalue reference to a CustomerOrder object and moves that CustomerOrder object to the back of the station's queue and returns a reference to the current object
	//
	Station & Station::operator+=(CustomerOrder&& order)
	{
		m_stationCustomerOrders.push(std::move(order));
		return *this;
	}
	bool Station::pop(CustomerOrder& ready)
	{
		if (m_stationCustomerOrders.empty())
			return false;
		else
			return true;
	}

	// A query that reports the state of the ItemSet object
	// 
	void Station::validate(std::ostream & os) const
	{
		os << " getName(): " << m_stationInventory.getName() << std::endl;
		os << " getSerialNumber(): " << m_stationInventory.getSerialNumber() << std::endl;
		os << " getQuantity(): " << m_stationInventory.getQuantity() << std::endl;
	}
}


