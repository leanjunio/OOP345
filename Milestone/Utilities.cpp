// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: November 17, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

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
    std::string query;

    if (more)
    {
        size_t delimiterPOS = str.find(getDelimiter(), next_pos + 1u);
        
        if (delimiterPOS != std::string::npos)
        {
            query = str.substr(next_pos, delimiterPOS - next_pos);
            more = true;
            if (delimiterPOS == next_pos)
                throw std::string("ERROR: Contiguous delimiters found");
            next_pos = delimiterPOS + 1u;
            
            if (m_widthField < static_cast<int>(query.size()))
                setFieldWidth(query.size());
        }
        else
        {
            query = str.substr(next_pos, str.length());
            more = false;
        }
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