#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H

#include <string>
#include "Item.h"

// ItemInfo object
struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0;
    bool m_fillState = false;

    ItemInfo(std::string src) : m_itemName(src) {};
};

/**
 * CustomerOrder
 * Manages a single order on the assembly line and contains the following information:
 * std::string m_name – the name of the customer (e.g., John, Sara, etc)
 * std::string m_product – the name of the product being assembled (e.g., Desktop, Laptop, etc)
 * unsigned int m_cntItem – a count of the number of items for the customer’s order
 * ItemInfo** m_lstItem – a dynamically allocated array of pointers. Each element of the array is a dynamically allocated object of type ItemInfo (see below). This is the resource that your class must manage.
 * static size_t m_widthField – the maximum width of a field, used for display purposes
 * 
 * NOTES:
 * m_lstItem is a dynamically allocated array of pointers
 * - Create pointer out of the ItemInfo object that is created and then add it to the array
 */
class CustomerOrder
{
    std::string m_name;
    std::string m_product;
    unsigned int m_cntItem;
    ItemInfo** m_lstItem;
    static size_t m_widthField;
  public:
    CustomerOrder();
    CustomerOrder(const std::string&);
    CustomerOrder(const CustomerOrder&);
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&&) noexcept;
    CustomerOrder& operator=(CustomerOrder&&);
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item& item, std::ostream&);
    void display(std::ostream&) const;
};

#endif // ! _CUSTOMERORDER_H