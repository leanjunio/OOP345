#include <string>
#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict
{
	// Extracts 4 tokens from the string that is passed and stores tokens in the object
	// 
	ItemSet::ItemSet(const std::string& record) 
	{
		size_t next_pos = record.find(m_utility.getDelimiter());
		m_name = record.substr(0,next_pos);
		m_serialNumber = std::stoul(m_utility.extractToken(record, next_pos));	// extract token and convert from string to ulong
		m_quantity = std::stoi(m_utility.extractToken(record, next_pos));
		m_description = m_utility.extractToken(record, next_pos);

		// update the utility fieldWidth with the largest name's length
		if (m_utility.getFieldWidth() < m_name.length())
			m_utility.setFieldWidth(m_name.length());
	}
	ItemSet::ItemSet(ItemSet && other)
	{
		if (this != &other)
		{
			m_name = other.m_name;
			m_description = other.m_description;
			m_serialNumber = other.m_serialNumber;
			m_quantity = other.m_quantity;

			other.m_name = { "" };
			other.m_description = { "" };
			other.m_serialNumber = { 0 };
			other.m_quantity = { 0 };
		}
	}
	const std::string & ItemSet::getName() const
	{
		return m_name;
	}
	const unsigned int ItemSet::getSerialNumber() const
	{
		return m_serialNumber;
	}
	const unsigned int ItemSet::getQuantity() const
	{
		return m_quantity;
	}
	ItemSet & ItemSet::operator--()
	{
		m_quantity--;
		m_serialNumber++;

		return *this;
	}
	void ItemSet::display(std::ostream & os, bool full) const
	{
		size_t fw = m_utility.getFieldWidth();

		if (full)
			os << std::left << std::setw(fw) << m_name << " [" << std::setw(5) << m_serialNumber << "] Quantity " << std::setw(3) << m_quantity << std::right<< " Description: " << m_description << std::endl;
	}
}

