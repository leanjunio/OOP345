#ifndef _SICT_CUSTOMER_ORDER_H
#define _SICT_CUSTOMER_ORDER_H

#include <string>
#include <memory>
#include <iostream>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
    /**
     * Contains all the functionality for handling customers as they move along the assembly line
     * CustomerOrder objects are unique, therefore they cannot be copied, but they are moveable
    */
    class CustomerOrder {
		/**
		 * Nested object that holds information about an Item
		*/
        struct ItemInfo {
            std::string s_name;
            int s_serialNumer;
            bool s_filled;
			ItemInfo() : s_name{ "" }, s_serialNumer{ 0 }, s_filled{ false } {}
		};
		
		ItemInfo* m_itemInfo;
        std::string m_customerName;
		std::string m_productName;
		size_t m_numItems;
		static size_t m_fieldWidth;
    public:
        CustomerOrder();
        explicit CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
        ~CustomerOrder();
        void fillItem (ItemSet&, std::ostream&);
        bool isFilled() const;
        bool isItemFilled(const std::string&) const;
        std::string getNameProduct() const;
        void display(std::ostream& os, bool showDetail = false) const;
    };
}

#endif // !_SICT_CUSTOMER_ORDER_H