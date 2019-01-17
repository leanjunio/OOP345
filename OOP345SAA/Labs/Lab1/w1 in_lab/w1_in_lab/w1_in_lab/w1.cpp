#include <iostream>
#include "process.h"

 int INITIAL = 3;

int main(int argc, char **argv)
{
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	// If no parameters are passed, return 1
	if (argc < 2)
	{
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}

	for (size_t i = 1; i < static_cast<size_t>(argc); i++)
		sict::process(argv[i]);

	return 0;
}