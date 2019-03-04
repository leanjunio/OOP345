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

			if (fs.is_open())
			{
				std::string line;
				while (std::getline(fs, line))
				{
					size_t space_pos = line.find(' ');
					int product_number = std::stoi(line.substr(0, space_pos));
					double cost = std::stod(line.substr(space_pos));

					products.push_back(sict::Product(product_number, cost));
				}
			}

			fs.close();
		}
	}

	void Sale::display(std::ostream & os) const
	{
		for (auto& i : products)
			i.display(os);
	}


	Sale::~Sale()
	{
	}
}

