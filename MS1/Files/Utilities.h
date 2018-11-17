// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: November 17, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _UTILITIES_H
#define _UTILITIES_H

// Utilities.h

#include <iostream>
#include <string>

class Utilities
{
    int m_widthField = 1;
    static char m_delimiter;
public:
    void setFieldWidth(size_t fieldWidth);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif