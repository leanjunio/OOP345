// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/21/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9
{

	void converter(char *t, char key, int n, const Cryptor &c)
	{
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char *file, char key, ostream *pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
				string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n"
			<< nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData()
	{
		delete[] text;
	}

	void SecureData::display(std::ostream &os) const
	{
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		auto f = std::bind(converter, text, key, nbytes, Cryptor());

		std::thread t1(f);
		std::thread t2(f);

		t1.join();
		t2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char *file)
	{
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			std::fstream f(file, std::ios::out | std::ios::binary | std::ios::trunc);
			f.write(text, nbytes);
			f.close();
		}
	}

	void SecureData::restore(const char *file, char key)
	{
		delete[] text;
		nbytes = 0;

		std::fstream f(file, std::ios::in | std::ios::binary);

		if (f.good())
		{
			f >> std::noskipws;

			while (!f.eof())
			{
				char temp;
				f >> temp;
				nbytes++;
			}

			nbytes--;
			f.clear();
			f.seekg(0, std::ios::beg);

			text = new char[nbytes + 1];

			f.read(text, nbytes);
			text[nbytes] = '\0';

			*ofs << "\n"
				<< nbytes << " bytes copied from binary file "
				<< file << " into memory.\n";

			encoded = true;

			code(key);

			*ofs << "Data decrypted in memory\n\n";
			f.close();
		}
	}

	std::ostream &operator<<(std::ostream &os, const SecureData &sd)
	{
		sd.display(os);
		return os;
	}
} // namespace w9
