#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"

extern int FW;

namespace sict
{
	Sale::Sale(const char* file)
	{
		if (file != nullptr && file[0] != '\0')
		{
			std::string buffer;
			size_t count = {0};
			std::ifstream fs;
			fs.open(file);
			if (fs.is_open())
			{
				while (std::getline(fs, buffer))
					count++;
				fs.clear();
				fs.seekg(0, std::ios::beg);
				for (size_t i = 0; i < count; i++)
					m_products.push_back(readRecord(fs));
				fs.close();
			}
			else
				throw "File cannot be opened";
		}
		else
			throw "File does not exist";
	}

	void Sale::display(std::ostream & os) const
	{
		os << "\nProduct No" << std::setw(FW) << "Cost" << std::endl;
		double total = { 0.0 };
		for (auto& i : m_products)
		{
			os << *i;
			os << std::fixed << std::setprecision(2);
			total += i->price();
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}
}

