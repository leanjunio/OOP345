#include <string>
#include "Utilities.h"

namespace sict
{
	Utilities::Utilities()
		: m_delimiter{'\0'}
		, m_fieldWidth{0}
	{
	}
	const std::string Utilities::extractToken(const std::string & str, size_t & next_pos)
	{
		m_delimiter = '|'; // NOTE: Manually added - should be fetched from the main function
		size_t delim_pos = str.find(m_delimiter);
		size_t word_length = next_pos;
		std::string item = str.substr(delim_pos - next_pos, next_pos);
		return item;
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

