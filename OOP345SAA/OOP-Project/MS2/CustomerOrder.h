#ifndef _SICT_CUSTOMER_ORDER_H
#define _SICT_CUSTOMER_ORDER_H

#include  <string>
#include <iostream>
#include "ItemSet.h"

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
			} m_ItemInfo;
    public:
        /**
         * Default Constructor that sets the object to a safe empty state
        */
        CustomerOrder();

        /**
         * One argument constructor that receives a string that contains at least 3 tokens:
         * - Customer's name
         * - Name of the product being assembled
         * - 3..n are names of the items to be added to the Product throughout the assembly process
         * If no items are requested to be added (no products are present within the string), throw an exception that says so
         * If items are present, allocate memory for each one
        */
        CustomerOrder(const std::string&);

        /**
         * Destructor that deallocates memory
        */
        ~CustomerOrder();

        /**
         * Modifier that checks each item request, fills it if the item is available and the request has not been filled and reports the filling in the following format:
         * Filled CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] OR
         * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] already filled
         * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] out of stock 
         * Also decrements the item stock by one
        */
        void fillItem (ItemSet&, std::ostream&);

        /**
         * Searches the list of items requested and returns true if all have ben filled
        */
        bool isFilled() const;

        /**
         * Receives an item name
         * search the list for that ItemName, return true if all requests for the item has been filled or if the item is not in the lists
        */
        bool isItemFilled(const std::string&) const;

        /**
         * Returns the name of the customer and their product in the following format:
         * CUSTOMER [PRODUCT]
        */
        std::string getNameProduct() const;

        /**
         * Inserts the data for the current object into the ostream
        */
        void display(std::ostream& os, bool showDetail) const;
    };
} // namespace sict

#endif // !_SICT_CUSTOMER_ORDER_H