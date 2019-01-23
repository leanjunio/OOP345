#ifndef _SICT_TEXT_H
#define _SICT_TEXT_H

#include <string>

namespace sict
{
	class Text
	{
		static int counter;

		std::string* p_strings;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text(Text&&);
		Text& operator=(const Text&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}

#endif // !_SICT_TEXT_H



