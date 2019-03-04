#include <string>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict
{
	ItemSet::ItemSet(const std::string record)
	{
		Utilities util;

		size_t delim_pos = record.find('|');
		m_name = util.extractToken(record, delim_pos);

		delim_pos = record.find('|', delim_pos);
		m_serialNumber = std::stoi(util.extractToken(record, delim_pos));


	}
	ItemSet::ItemSet()
	{
	}


	ItemSet::~ItemSet()
	{
	}
}

