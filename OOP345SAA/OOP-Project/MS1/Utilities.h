#ifndef _SICT_UTILITIES_H
#define _SICT_UTILITIES_H

#include <string>

namespace sict
{
	class Utilities
	{
		static char m_delimiter;
		static size_t m_fieldWidth;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif // !_SICT_UTILITIES_H


