// Workshop 9 - Multi-Threading
// SecureData.cpp
// Chris Szalwinski after Cornel Barna
// 2019/03/19

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace sict {

	// encrypts information using the key
	//
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	// copies the file into memory
	//
	SecureData::SecureData(const char* file, char key, ostream* pOfs) {
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
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	// deallocate resource
	//
	SecureData::~SecureData() {
		delete[] text;
	}

	// Displays the file contents
	//
	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	// creates another thread while the main application is running
	//
	void SecureData::code(char key) {
		std::thread t1(converter, text, key, nbytes, Cryptor());
		t1.join();
		encoded = !encoded;
	}

	// creates another file as a "backup"
	//
	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream ofs(file, std::ofstream::binary);

			// TODO: write data into the binary file
			//         and close the file
			ofs.write(text, nbytes);
			ofs.close();
		}
	}

	// restores the file that was encrypted
	//
	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream ifs(file, std::ifstream::binary);


		// TODO: - allocate memory here for the file content

		char* buffer = new char[nbytes];


		// TODO: - read the content of the binary file
		ifs.read(buffer, nbytes);



		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	// Output stream
	//
	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
