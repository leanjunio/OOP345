// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/12/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	/** 
	 * Uses the overloaded operator to "merge" the Description, price into 1 Product 
	 * - Compares the elements within the two received Lists (desc and price) for commmon product codes
	 */
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		
		for(size_t i = 0; i < desc.size(); i++)
		{
			for(size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{
					Product* ptr = new Product(desc[i].desc, price[n].price);	
					ptr->validate();
					priceList += ptr;

					delete ptr;
					ptr = nullptr;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;

		for(size_t i = 0; i < desc.size(); i++)
		{
			for(size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[n].price));
					ptr->validate();
					priceList += ptr;
				}
			}
		}

		return priceList;
	}
}