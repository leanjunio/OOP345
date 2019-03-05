#ifndef _SICT_ITEMSET_H
#define _SICT_ITEMSET_H

#include <string>

namespace sict
{
	class ItemSet
	{
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int m_quantity;
	public:
		explicit ItemSet(const std::string);
		ItemSet(ItemSet&&);
		ItemSet(const ItemSet&) = delete;
		ItemSet& operator=(const ItemSet&) = delete;
		ItemSet& operator=(ItemSet&&) = delete;
		ItemSet();
		~ItemSet();

		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();

		void display(std::ostream& os, bool full) const;
	};
}

#endif // !_SICT_ITEMSET_H
