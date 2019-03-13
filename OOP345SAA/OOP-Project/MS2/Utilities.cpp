#include <string>
#include <iostream>
#include "Utilities.h"

namespace sict
{
	char Utilities::m_delimiter = '\0';
	size_t Utilities::m_fieldWidth = { 0 };
	
	// Default Constructor
	// 
	Utilities::Utilities() {}
	
	// Extracts the next token in the string starting at the position next_pos
	// 
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos) 
	{
		size_t next_delimiter_pos = str.find(m_delimiter, next_pos + 1);	// find the next delimiter from 1 character after the previous one
		size_t word_length = (next_delimiter_pos - next_pos) - 1;			// get the length of the next word
		std::string token = str.substr(next_pos + 1, word_length);			// extract the string that starts from next_pos with the length of the next word
		next_pos = next_delimiter_pos;										// sets the next_pos to contain the position of the upcoming delimiter
		return token;
	}
	const char Utilities::getDelimiter() const
	{
		return m_delimiter;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_fieldWidth;
	}
	void Utilities::setDelimiter(const char d) 
	{
		m_delimiter = { d };
	}
	void Utilities::setFieldWidth(size_t fw)
	{
		m_fieldWidth = { fw };
	}
}

