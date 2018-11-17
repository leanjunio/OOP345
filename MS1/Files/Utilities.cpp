#include <string>
#include "Utilities.h"

char Utilities::m_delimiter;

void Utilities::setFieldWidth(size_t fieldWidth)
{
    m_widthField = fieldWidth;
}

size_t Utilities::getFieldWidth() const
{
    return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
    // Extract tokens from string until delimiter
    // more represents if there are more tokens
    std::string query;

    if (more)
    {
        size_t delimiterPOS = str.find(getDelimiter(), next_pos + 1u);
        
        query = str.substr(next_pos, delimiterPOS - next_pos);
        more = true;
        next_pos = delimiterPOS + 1u;
    }

    return query;
}

void Utilities::setDelimiter(const char delimiter)
{
    Utilities::m_delimiter = delimiter;
}

const char Utilities::getDelimiter() const
{
    return m_delimiter;
}