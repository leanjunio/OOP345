// Item.cpp

#include "Item.h"

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
}

// returns the name of the current Item object
// 
const std::string& Item::getName() const { return m_name; }

// returns the next serial number to be used on the assembly line and increments m_serialNumber
// 
const unsigned int Item::getSerialNumber() { return 0; }

// returns the remaining quantity of the current Item object
// 
const unsigned int Item::getQuantity() { return 0; }

//  substracts 1 from the available quantity; should not go below 0.
// 
void Item::updateQuantity() {  if ((m_quantity - 1) != 0) m_quantity--; }




