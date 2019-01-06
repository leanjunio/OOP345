#include <iostream>
#include "Name.h"


Name::Name()
	: m_First{""}
	, m_Last{""}
{
}

Name::Name(std::string First, std::string Last)
	: m_First{First}
	, m_Last{Last}
{
}

void Name::Display() const
{
	std::cout << "First Name: " << std::endl;
	std::cout << "Last Name: " << std::endl;
}
