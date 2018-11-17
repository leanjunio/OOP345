// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: November 17, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _ITEM_H
#define _ITEM_H

// Item.h

#include <string>

class Item
{
    std::string m_name;
    std::string m_description;
    std::string m_serialNumber;
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




