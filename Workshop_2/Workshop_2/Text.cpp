// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <algorithm>
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
		m_StringPtr(new std::string)
	{
		if (m_FileName != "Unknown" && !m_FileName.empty())
			readFile();
	} 

	// Read file into std::string::m_StringPtr
	void Text::readFile()
<<<<<<< HEAD
		// read the file into string
=======
>>>>>>> w2_windows
	{
		std::ifstream file(m_FileName);
		std::stringstream buffer;

		buffer << file.rdbuf();
<<<<<<< HEAD
		std::string buf_string(buffer.str());
		m_StringPtr.reset(&buf_string);
=======
		*m_StringPtr = buffer.str();
>>>>>>> w2_windows
	}

	// Copy Constructor
	Text::Text(const Text& other)
		: m_StringPtr(new std::string)
	{
		memcpy(m_StringPtr, other.m_StringPtr, sizeof(std::string));
	}

	// Copy Assignment Operator
	Text & Text::operator=(const Text & old)
	{
<<<<<<< HEAD
		if (this != &old)
		{
			m_FileName = old.m_FileName;

			if (old.m_StringPtr != nullptr)
				m_StringPtr.reset(new std::string);
			else
				m_StringPtr = nullptr;
		}
=======
		if (this == &old)
			return *this;

		m_FileName = old.m_FileName;
		memcpy(m_StringPtr, old.m_StringPtr, sizeof(std::string));
>>>>>>> w2_windows
		return *this;
	}

	// Move Constructor
	Text::Text(Text&& src)
		: m_StringPtr(src.m_StringPtr)
	{
		src.m_StringPtr = nullptr;
	}

	// Move operator
	Text& Text::operator=(Text&& src)
	{
		if (this == &src)
			return *this;

		m_FileName = src.m_FileName;
		m_StringPtr = src.m_StringPtr;

		src.m_StringPtr = nullptr;
		src.m_FileName = "";
		return *this;
	}

	// Destructor
	Text::~Text()
	{
<<<<<<< HEAD
		// m_StringPtr.reset();
=======
		// delete m_StringPtr;
		m_StringPtr = nullptr;
>>>>>>> w2_windows
	}
	size_t Text::size() const
	{
		return size_t(1);
	}
}
