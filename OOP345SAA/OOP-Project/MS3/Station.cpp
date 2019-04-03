#include "Station.h"
#include "ItemSet.h"

namespace sict
{
	Station::Station(const std::string& string)
		: m_set(string)
	{
	}
	void Station::display(std::ostream& os) const
	{
		m_set.display(os, true);
	}
	void Station::fill(std::ostream& os)
	{
		if (!m_customerOrders.empty())
			m_customerOrders.back().fillItem(m_set, os);
	}
	const std::string& Station::getName() const
	{
		return m_set.getName();
	}
	bool Station::hasAnOrderToRelease() const
	{
		/*if (m_customerOrders.empty())
			return false;
		else
		{
			if (m_customerOrders.front().isFilled())
		}*/
		return false;
	}
	Station& Station::operator--()
	{
		--m_set;
		return *this;
	}
	Station & Station::operator+=(CustomerOrder&& order)
	{
		m_customerOrders.push(order);
		return *this;
	}
	bool Station::pop(CustomerOrder& ready)
	{
		return false;
	}
	void Station::validate(std::ostream & os) const
	{
		os << "getName(): " << m_set.getName() << std::endl;
		os << "getSerialNumber(): " << m_set.getSerialNumber() << std::endl;
		os << "getQuantity(): " << m_set.getQuantity() << std::endl;
	}
}


