#include <iostream>
#include "process.h"

int main(int argc, char *argv[])
{
	// If no parameters are passed, return 1
	if (argc < 2)
	{
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}

	for (size_t i = 1; i < argc; i++)
		sict::process(argv[i]);

	return 0;
}