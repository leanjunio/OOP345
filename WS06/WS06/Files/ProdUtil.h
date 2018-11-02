// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/2/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// ProdUtil.h

#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}

#endif