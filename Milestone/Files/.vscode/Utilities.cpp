// Utilities.cpp

#include "Utilities.h"

// sets the field width of the current object to the value of the parameter
//
void Utilities::setFieldWidth(size_t fieldWidth) { m_widthField = fieldWidth; }

// returns the field width of the current object
//
size_t Utilities::getFieldWidth() const { return m_widthField; }

// extracts tokens from the first parameter
// This function uses the delimiter to extract the next token from str starting at next_pos
// If successful, it returns the extracted token found and sets more to true; false otherwise
// This function reports an exception if there are two delimiters with no token between them
// This function updates the current object’s m_widthField data member if its current value is less than the size of the token extracted.
// Note: str represents a single line read from an input file
// 
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{

}

// sets the delimiter for this class to the character received
// 
void Utilities::setDelimiter(const char delimiter) { m_delimeter = delimiter; }

// returns the delimiter character of the current object
// 
const char Utilities::getDelimiter() const { return m_delimeter; }