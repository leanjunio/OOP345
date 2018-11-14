#ifndef _ITEM_H
#define _ITEM_H

// Item.h

#include <string>

class Item
{
    std::string m_name;
    std::string m_description;
    int m_serialNumber;
    int m_quantity;
    static int m_widthField;
public:
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
  
};

#endif // _ITEM_H




