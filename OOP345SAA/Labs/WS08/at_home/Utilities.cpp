// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t x = 0; x < price.size(); ++x) {
				if (desc[i].code == price[x].code) {
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;	// deallocate p
					p = { nullptr };
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t x = 0; x < price.size(); ++x) {
				if (desc[i].code == price[x].code) {
					std::unique_ptr<Product> p { new Product(desc[i].desc, price[x].price) };
					p->validate();
					priceList += p;
				}
			}
		}





		return priceList;
	}
}