#include <fstream>
#include <utility>
#include "Text.h"

namespace sict
{
	int Text::counter = 0;

	Text::Text()
		: p_strings{nullptr}
	{
	}

	Text::Text(const char * filename)
	{
		std::string buffer = {};
		std::ifstream file;
		file.open(filename);

		// count lines in file
		if (file.is_open())
		{
			while (std::getline(file, buffer))
				++counter;
		}

		// allocate memory
		p_strings = new std::string[counter];

		int i = 0;
		std::string line = {};

		while (std::getline(file, line))
			p_strings[i] = line;
	}

	Text::Text(const Text& other)
	{
		*this = other;
	}

	Text::Text(Text&& src)
		: p_strings(nullptr)
	{
		p_strings = src.p_strings;
		src.p_strings = nullptr;
	}

	Text & Text::operator=(const Text &other)
	{
		if (this != &other)
		{
			// shallow copy
			counter = other.counter;
			p_strings = new std::string[counter];

			// deep copy
			for (size_t i = 0; i < (size_t)counter; i++)
				p_strings[i] = other.p_strings[i];
		}
		return *this;
	}

	Text & Text::operator=(Text&& other)
	{
		if (this != &other)
		{
			// free the memory
			delete[] p_strings;

			// assign other.p_strings address from other object to current object
			p_strings = other.p_strings;

			other.p_strings = nullptr;
		}
		
		return *this;
	}

	Text::~Text()
	{
		delete[] p_strings;
		p_strings = nullptr;
	}
	size_t Text::size() const
	{
		return counter;
	}
}

