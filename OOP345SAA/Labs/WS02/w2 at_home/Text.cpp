#include <fstream>
#include "Text.h"

namespace sict
{
	int Text::counter = 0;

	Text::Text()
		: p_strings(nullptr)
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

	Text & Text::operator=(const Text &other)
	{
		if (this != &other)
		{
			// shallow copy
			counter = other.counter;

			//delete[] p_strings;

			p_strings = new std::string[counter];

			for (size_t i = 0; i < (size_t)counter; i++)
				p_strings[i] = other.p_strings[i];
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

