/*

	Lambda Functions - An anonymous function nested within the body of another function representing an unnamed function object

	[capture-list](parameter-declaration-clause) -> optional return type { // body }

*/
#include <iostream>

int main()
{
	{
		// Lambda Expressions
		auto hello = []() { return "Hello World"; };
		auto add4 = [](int i) { return i + 4; };
		auto sub4 = [](int i) {	return i - 4; };

		// Calls on the lambda function
		std::cout << hello() << std::endl;
		std::cout << add4(10) << std::endl;
		std::cout << sub4(10) << std::endl;
	}
}