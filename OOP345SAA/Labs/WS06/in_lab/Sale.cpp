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
			std::ifstream fs;
			fs.open(file);

			// Call readRecord()

			fs.close();
		}
	}

	void Sale::display(std::ostream & os) const
	{
		std::cout << "Product No      Cost" << std::endl;
		double total = { 0.0 };
		for (auto& i : products)
		{
			os << i;
			total += i->price();
		}
		std::cout << "Total: " << total << std::endl;
	}


	Sale::~Sale()
	{
	}
}
