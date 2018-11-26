// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: November 17, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

// CustomerOrder.cpp

#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
    : m_name(""),
      m_product(""),
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
    m_product = localUtility.extractToken(record, next_pos, more);

    if (localUtility.getFieldWidth() > m_widthField)
        m_widthField = localUtility.getFieldWidth();

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
    localUtility.setFieldWidth(0);
    for (int i = 0; i < m_cntItem; i++)
        m_lstItem[i] = new ItemInfo(localUtility.extractToken(record, beg, more));

}

CustomerOrder::CustomerOrder(const CustomerOrder& other)
{
    throw std::string("Invalid Operation: CustomerOrder objects cannot be copied.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept
{
    *this = std::move(other);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        m_product = other.m_product;
        m_cntItem = other.m_cntItem;
        m_lstItem = other.m_lstItem;

        other.m_lstItem = nullptr;
    }

    return *this;
}

CustomerOrder::~CustomerOrder()
{
    delete [] m_lstItem;
}

bool CustomerOrder::getItemFillState(std::string item) const
{
    
    for (int i = 0; i < m_cntItem; i++)
        if (m_lstItem[i]->m_itemName == item)
            return m_lstItem[i]->m_fillState;
    
    return true;
}

bool CustomerOrder::getOrderFillState() const
{
    for (int i = 0; i < m_cntItem; i++)
        return (m_lstItem[i]->m_fillState) ? true : false;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
    for (int i = 0; i < m_cntItem; i++)
    {
        if (m_lstItem[i]->m_itemName == item.getName()) 
        {
            if (item.getQuantity() > 0) 
            {
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                item.updateQuantity();
                m_lstItem[i]->m_fillState = true;
                os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]";
            } 
            else
                os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]";
            
            os << std::endl;
        }
    }
}

void CustomerOrder::display(std::ostream& os) const
{
    os << m_name << " - " << m_product << std::endl;

    for(size_t i = 0; i < m_cntItem; i++)
    {
        os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] " 
           << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName
           << " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
    }
}

