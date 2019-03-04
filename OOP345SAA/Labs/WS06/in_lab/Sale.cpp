#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"

namespace sict
{
	Sale::Sale(const char* file)
	{
		if (file != nullptr && file[0] != '\0')
		{
			std::string buffer;
			int cnt = {0};
			std::ifstream fs;
			fs.open(file);
			while (std::getline(fs, buffer))
				cnt++;
			fs.clear();
			fs.seekg(0, std::ios::beg);
			for (size_t i = 0; i < cnt; i++)
				products.push_back(readRecord(fs));
			fs.close();
		}
	}

	void Sale::display(std::ostream & os) const
	{
		std::cout << "Product No      Cost" << std::endl;
		double total = { 0.0 };
		for (auto& i : products)
		{
			os << *i;
			total += i->price();
		}
		std::cout << "Total: " << total << std::endl;
	}


	Sale::~Sale()
	{
	}
}

