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
		


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers


		return priceList;
	}
}