#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	size_t CustomerOrder::m_fieldWidth = 0;

	/**
	 * Default Constructor that sets the object to a safe empty state
	*/
	CustomerOrder::CustomerOrder() : m_itemInfo{ nullptr }, m_customerName{ "" }, m_productName{ "" }, m_numItems{ 0 } {}
	/**
	 * One argument constructor that receives a string that contains at least 3 tokens:
	 * - Customer's name
	 * - Name of the product being assembled
	 * - 3..n are names of the items to be added to the Product throughout the assembly process
	 * If no items are requested to be added (no products are present within the string), throw an exception that says so
	 * If items are present, allocate memory for each one
	*/
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

	CustomerOrder::CustomerOrder(CustomerOrder&& other) {
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

	/**
	 * Destructor that deallocates memory
	*/
	CustomerOrder::~CustomerOrder() {
		delete[] m_itemInfo;
		m_itemInfo = { nullptr };
	}

	/**
	 * Modifier that checks each item request, fills it if the item is available and the request has not been filled and reports the filling in the following format:
	 * Filled CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] OR
	 * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] already filled
	 * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] out of stock
	 * Also decrements the item stock by one
	*/
	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < m_numItems; ++i) {
			if (item.getName() == m_itemInfo[i].s_name) {
				if (item.getQuantity() == 0)
					os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "] out of stock" << std::endl;
				else 
				{
					if (m_itemInfo[i].s_filled)
						os << " Unable to fill " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "] already filled" << std::endl;
					else 
					{
						m_itemInfo[i].s_serialNumer = item.getSerialNumber();
						m_itemInfo[i].s_filled = true;
						item.operator--();
						os << " Filled " << m_customerName << " [" << m_productName << "][" << m_itemInfo[i].s_name << "][" << m_itemInfo[i].s_serialNumer << "]" << std::endl;
					}
				}
			}
		}
	}

	/**
	 * Searches the list of items requested and returns true if all have ben filled
	*/
	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_numItems; ++i) 
			if (!m_itemInfo[i].s_filled)
				return false;
		return true;
	}

	/**
	 * Receives an item name
	 * search the list for that ItemName, return true if all requests for the item has been filled or if the item is not in the lists
	*/
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_numItems;  ++i) {
			if (m_itemInfo[i].s_name == itemName) {
				if (!m_itemInfo->s_filled)
					return false;
			}
		}
		return true;
	}

	/**
	 * Returns the name of the customer and their product in the following format:
	 * CUSTOMER [PRODUCT]
	*/
	std::string CustomerOrder::getNameProduct() const {
		return std::string(m_customerName) + "[" + std::string(m_productName) + "]";
	}

	/**
	 * Inserts the data for the current object into the ostream
	 * Has a default showDetail as false
	 * Displays in the following format:
	 * Name       [Product]
	 *            Part 1
	 *            Part 2
	 *            Part 3
	 *            Part 4
	*/
	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		os << std::left << std::setw(m_fieldWidth) << m_customerName << " [" << m_productName << "]" << std::endl;
		if (!showDetail) {

			for (size_t i = 0; i < m_numItems; ++i) {
				os << std::setfill(' ') << std::setw(m_fieldWidth + 1) << "    " << std::right << m_itemInfo[i].s_name << std::endl;
			}
		}
	}
}