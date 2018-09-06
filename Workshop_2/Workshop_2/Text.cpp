// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion:
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
	Text::Text(std::string file)
		: m_FileName(file), m_StringPtr(nullptr)
	{
		if (m_FileName != "Unknown" && !m_FileName.empty())
			readFile();
	}

	void Text::readFile()
		// read the file into string
	{
		std::ifstream file(m_FileName);
		std::stringstream buffer;

		buffer << file.rdbuf();
		std::string buf_string(buffer.str());
		m_StringPtr.reset(&buf_string);
	}

	Text::Text(const Text & other)
	{
		m_StringPtr = nullptr;
		*this = other;
	}

	Text & Text::operator=(const Text & old)
	{
		if (this != &old)
		{
			m_FileName = old.m_FileName;

			if (old.m_StringPtr != nullptr)
				m_StringPtr.reset(new std::string);
			else
				m_StringPtr = nullptr;
		}
		return *this;
	}

	Text::~Text()
	{
		// m_StringPtr.reset();
	}
	size_t Text::size() const
	{
		return size_t(1);
	}
}
