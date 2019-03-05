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
			int count = {0};
			std::ifstream fs;
			fs.open(file);
			while (std::getline(fs, buffer))
				count++;
			fs.clear();
			fs.seekg(0, std::ios::beg);
			for (size_t i = 0; i < count; i++)
				products.push_back(readRecord(fs));
			fs.close();
		}
	}

	void Sale::display(std::ostream & os) const
	{
		os << "Product No" << std::setw(10) << "Cost" << std::endl;
		double total = { 0.0 };
		for (auto& i : products)
		{
			os << *i;
			os << std::fixed << std::setprecision(2);
			total += i->price();
		}
		os << std::setw(10) << "Total" << std::setw(10) << total << std::endl;
	}
}

