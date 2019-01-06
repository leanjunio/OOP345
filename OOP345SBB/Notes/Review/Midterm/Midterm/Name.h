#pragma once
#include <string>

class Name
{
	std::string m_First;
	std::string m_Last;
public:
	Name();
	Name(std::string First, std::string Last);

	void Display() const;
};

