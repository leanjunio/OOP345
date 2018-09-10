// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: September 6, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
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
		// ERROR: Doesn't permanently get stored in m_StringPtr
		while (std::getline(file, *m_StringPtr))
			m_Count++;
	}

	// Copy Constructor
	Text::Text(const Text& other)
		: m_FileName(other.m_FileName),
		m_StringPtr(new std::string(*other.m_StringPtr)),
		m_Count(other.m_Count)
	{
	}

	// Copy Assignment Operator
	Text& Text::operator=(const Text& old)
	{
		if (this == &old)
			return *this;

		delete m_StringPtr;
		m_Count = old.m_Count;
		m_FileName = old.m_FileName;

		if (old.m_StringPtr != nullptr)
			m_StringPtr = new std::string(*old.m_StringPtr);
		else
			m_StringPtr = nullptr;

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
		delete m_StringPtr;
		m_StringPtr = nullptr;
	}

	size_t Text::size() const
	{
		return m_Count;
	}
}
