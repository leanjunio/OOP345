// CustomerOrder.cpp

#include <iostream>
#include "Utilities.h"
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
    : m_name("N/A"),
      m_product("N/A"),
      m_cntItem(0),
      m_lstItem(nullptr)
{
}

CustomerOrder::CustomerOrder(const std::string &record)
    : CustomerOrder()
{
    Utilities localUtility;
    bool more = true;
    size_t next_pos = 0u, beg = 0u;

    m_name = localUtility.extractToken(record, next_pos, more);
    beg = next_pos;
    m_cntItem = 0u;
    // Count how many products exists
    while (more)
    {
        localUtility.extractToken(record, next_pos, more);
        m_cntItem++;
    }

    // Allocate memory
    m_lstItem = new ItemInfo*[m_cntItem];
    more = true;

    // Take the addresses of the extracted tokens and add them into m_lstItem
    for (int i = 0; i < m_cntItem; i++)
        m_lstItem[i] = new ItemInfo(localUtility.extractToken(record, beg, more));
}

CustomerOrder::CustomerOrder(const CustomerOrder& other)
{
    throw std::string("Invalid Operation: CustomerOrder objects cannot be copied.");
}

CustomerOrder::~CustomerOrder()
{
    delete [] m_lstItem;
}

void CustomerOrder::display(std::ostream& os) const
{
    os << m_name << " - " << m_product << std::endl;
}

