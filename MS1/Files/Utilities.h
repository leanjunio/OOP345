#ifndef _UTILITIES_H
#define _UTILITIES_H

// Utilities.h

#include <iostream>
#include <string>

class Utilities
{
    int m_widthField;
    static char m_delimeter;
public:
    void setFieldWidth(size_t fieldWidth = 1);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif