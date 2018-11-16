#include <string>
#include "Utilities.h"

void Utilities::setFieldWidth(size_t fieldWidth = 1)
{
    m_widthField = fieldWidth;
}

size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    
}

void Utilities::setDelimiter(const char delimiter)
{
    m_delimeter = delimiter;
}

const char Utilities::getDelimiter() const
{
    return m_delimeter;
}