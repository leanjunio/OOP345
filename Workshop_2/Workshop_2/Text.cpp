// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: September 6, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Text.h"

namespace w2
{	
	// Accepts a filename and set to safe-empty
	Text::Text(std::string file)
		: m_FileName(file), 
		m_StringPtr(new std::string),
		m_Count(0)
	{
		if (m_FileName != "Unknown" && !m_FileName.empty())
			readFile();
	} 

	// Read file into std::string::m_StringPtr
	void Text::readFile()
	{
		std::ifstream file(m_FileName);
		std::stringstream buffer;

		// put the file text in m_StringPtr and count
		while (std::getline(file, *m_StringPtr))
			m_Count++;
	}

	// Copy Constructor
	Text::Text(const Text& other)
		: m_StringPtr(new std::string),
		m_Count(other.m_Count)
	{
		memcpy(m_StringPtr, other.m_StringPtr, sizeof(std::string));
	}

	// Copy Assignment Operator
	Text & Text::operator=(const Text & old)
	{
		if (this == &old)
			return *this;

		m_Count = old.m_Count;
		m_FileName = old.m_FileName;
		memcpy(m_StringPtr, old.m_StringPtr, sizeof(std::string));
		return *this;
	}

	// Move Constructor
	Text::Text(Text&& src)
		: m_StringPtr(src.m_StringPtr),
		m_Count(src.m_Count)
	{
		src.m_StringPtr = nullptr;
	}

	// Move operator
	Text& Text::operator=(Text&& src)
	{
		if (this == &src)
			return *this;

		m_FileName = src.m_FileName;
		m_Count = src.m_Count;
		m_StringPtr = src.m_StringPtr;

		src.m_StringPtr = nullptr;
		src.m_FileName = "";
		return *this;
	}

	// Destructor
	Text::~Text()
	{
		m_StringPtr = nullptr;
	}

	size_t Text::size() const
	{
		return m_Count;
	}
}
