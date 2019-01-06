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
#include "Text.h"

namespace w2
{	
	// Accepts a filename and set to safe-empty
	Text::Text(std::string file)
		: m_Count(0),
		m_StringPtr(new std::string[m_Count]),
		m_FileName(file)
	{
		// If all the conditions are met
		if (!m_FileName.empty())
		{
			countLines();
			readFile();
		}
	} 

	// Read file into std::string::m_StringPtr
	void Text::readFile()
	{
		std::string buf;							// will contain one line from the file
		std::ifstream file(m_FileName);	
		int i = 0;

		m_StringPtr = new std::string[m_Count];		// allocate memory of size m_Count

		while (std::getline(file, buf))				// goes through the file while storing one line at a time in buf
		{
			m_StringPtr[i] = buf;
			i++;
		}
	}

	// Counts how many lines are in the file
	void Text::countLines()
	{
		std::ifstream file(m_FileName);
		std::string buf;

		while (std::getline(file, buf))
			m_Count++;
	}

	// Copy Constructor - copies the elements from other into 'this'
	Text::Text(const Text& other)
	{
		*this = other;
	}

	// Copy Assignment Operator
	Text& Text::operator=(const Text& old)
	{
		// Shallow Copy
		m_Count = old.m_Count;		
		m_FileName = old.m_FileName;

		if (this != &old)
		{
			// Allocate new memory
			delete[] m_StringPtr;
			m_StringPtr = new std::string[m_Count];

			// Deep copy - copies the content of the resource not just the address
			for (size_t i = 0; i < m_Count; i++)
				m_StringPtr[i] = old.m_StringPtr[i];
		}
		return *this;
	}

	// Move Constructor
	Text::Text(Text&& src)
	{
		*this = std::move(src);
	}

	// Move operator
	Text& Text::operator=(Text&& src)
	{
		if (this != &src)
		{
			m_FileName = src.m_FileName;
			m_Count = src.m_Count;

			// Deallocate the memory for the current object's m_StringPtr
			delete[] m_StringPtr;

			m_StringPtr = src.m_StringPtr;
			src.m_StringPtr = nullptr;
		}
		return *this;
	}

	// Destructor
	Text::~Text()
	{
		delete[] m_StringPtr;
		m_StringPtr = nullptr;
	}

	// Return size of Count
	size_t Text::size() const
	{
		return m_Count;
	}
}
