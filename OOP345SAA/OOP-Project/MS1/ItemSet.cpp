#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict
{
	ItemSet::ItemSet(const std::string record)
	{
		Utilities util;
		size_t prev_pos = { 0 };
		size_t delim_pos = record.find('|');
		m_name = util.extractToken(record, delim_pos);

		delim_pos = record.find('|', delim_pos + 1);
		m_serialNumber = std::stoi(util.extractToken(record, delim_pos));
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
	ItemSet::~ItemSet()
	{
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
		if (!full)
		{

		}
	}
}

