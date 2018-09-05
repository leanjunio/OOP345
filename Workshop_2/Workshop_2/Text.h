// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _W2_TEXT_H
#define _W2_TEXT_H

#include <string>
#include <memory>

namespace w2
{
	class Text
	{
		std::unique_ptr<std::string> m_StringPtr;
		std::string m_FileName;
	public:
		Text(std::string file = "Unknown");
		void readFile();
		Text(const Text& other);
		Text& operator=(const Text& old);
		/*Text(Text&& src);
		Text& operator=(Text&& src);*/
		~Text();

		// Returns the number of records of text data
		size_t size() const;
	};
}

#endif // !_W2_TEXT_H


