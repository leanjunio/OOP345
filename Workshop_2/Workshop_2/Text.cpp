// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include <fstream>
#include <sstream>
#include "Text.h"

namespace w2
{	
	Text::Text(std::string file)
		: m_FileName(file), m_StringPtr(nullptr)
	{
		if (!m_FileName.empty())
			readFile();
	}

	void Text::readFile()
		// reads the file into m_StringPtr
	{
		std::ifstream file(m_FileName);
		std::stringstream buffer;

		buffer << file.rdbuf();
		*m_StringPtr = buffer.str();
	}

	Text::~Text()
	{
		delete[] m_StringPtr;
	}
}
