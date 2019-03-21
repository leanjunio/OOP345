#include <string>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"

namespace sict {

	size_t CustomerOrder::m_fieldWidth = 0;

	CustomerOrder::CustomerOrder() : m_itemInfo{ nullptr }, m_customerName{ "" }, m_productName{ "" }, m_numItems{ 0 } {}

	CustomerOrder::CustomerOrder(const std::string& record) : CustomerOrder() {
		Utilities utility;
		
		size_t delimiter_pos = record.find(utility.getDelimiter());
		m_customerName = record.substr(0, delimiter_pos);

		if (m_fieldWidth < utility.getFieldWidth())
			m_fieldWidth = utility.getFieldWidth();

		m_productName = utility.extractToken(record, delimiter_pos);
		
		m_numItems = std::count(record.begin(), record.end(), utility.getDelimiter()) - 1;
		m_itemInfo = new ItemInfo[m_numItems];

		if (m_numItems >= 1) {
			for (size_t i = 0; i < m_numItems; i++)
				m_itemInfo[i].s_name = utility.extractToken(record, delimiter_pos);
		} else {
			throw "***No items are found***";
		}	
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other)
	{
		*this = std::move(other);
	}

	CustomerOrder & CustomerOrder::operator=(CustomerOrder&& other) {
		if (this != &other) {
			m_customerName = other.m_customerName;
			m_productName = other.m_productName;
			m_numItems = other.m_numItems;
			m_itemInfo = other.m_itemInfo;

			other.m_itemInfo = { nullptr };
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		delete[] m_itemInfo;
		m_itemInfo = { nullptr };
	}

	void CustomerOrder::fillItem(ItemSet &, std::ostream &)
	{
	}

	bool CustomerOrder::isFilled() const
	{
		return false;
	}

	bool CustomerOrder::isItemFilled(const std::string &) const
	{
		return false;
	}

	std::string CustomerOrder::getNameProduct() const
	{
		return std::string();
	}

	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		os << std::left << std::setw(m_fieldWidth) << m_customerName << " [" << m_productName << "]" << std::endl;

		for (size_t i = 0; i < m_numItems; ++i) {
			os << std::setw(m_fieldWidth) << m_itemInfo[i].s_name << std::endl;
		}
	}

}