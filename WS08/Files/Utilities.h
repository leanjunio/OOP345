#ifndef W8_UTILITIES_H
#define W8_UTILITIES_H
#include "List.h"
#include "Element.h"

namespace w8 {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif