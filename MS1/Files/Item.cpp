// Item.cpp

#include <iomanip>
#include "Utilities.h"
#include "Item.h"

// Instantiate static member "m_widthField"
int Item::m_widthField = 0;

// upon instantiation, an Item object receives a reference to an unmodifiable std::string
// This string contains a single record (one line) that has been retrieved from the input file specified by the user.
// the constructor then uses an Utilities object (created local in the function) to extract each token from the record and populates the Item object accordingly.
// Note: You can assume that a record from the file contains 4 fields separated by a delimiter, in the following order:
// • name of item
// • starting serial number
// • quantity in stock
// • description
// the delimiter of the tokens is a single character, specified by the client and stored into the Utilities object.
// once the constructor has extracted all of the tokens from the record, it updates Item::m_widthField to the maximum value of Item::m_widthField and Utilities::m_widthField
// Note: the display(...) member function uses this field width to align the output across all of the records retrieved from the file.
// 
Item::Item(const std::string& singleRecord)
{
    Utilities localUtility;

    // Set defaults for the next_pos and more
    bool more = true;
    size_t next_pos = 0u;

    m_name = localUtility.extractToken(singleRecord, next_pos, more);
    m_serialNumber = localUtility.extractToken(singleRecord, next_pos, more);
    
    if (m_serialNumber.length() < 6)
        m_serialNumber.insert(0, "0");
    
    m_quantity = std::stoi(localUtility.extractToken(singleRecord, next_pos, more));
    m_description = localUtility.extractToken(singleRecord, next_pos, more);

    m_widthField = localUtility.getFieldWidth();
}

// returns the name of the current Item object
// 
const std::string& Item::getName() const { return m_name; }

// returns the next serial number to be used on the assembly line and increments m_serialNumber
// 
const unsigned int Item::getSerialNumber() { return std::stoi(m_serialNumber); }

// returns the remaining quantity of the current Item object
// 
const unsigned int Item::getQuantity() { return m_quantity; }

//  substracts 1 from the available quantity; should not go below 0.
// 
void Item::updateQuantity() {  if ((m_quantity - 1) != 0) m_quantity--; }

void Item::display(std::ostream& os, bool full) const
{
    os << std::setw(m_widthField) << std::left << m_name << "[" << m_serialNumber << "] ";
    if (full)
        os << "Quantity: " << m_quantity << " Description: " << m_description;
    os << std::endl;
}




