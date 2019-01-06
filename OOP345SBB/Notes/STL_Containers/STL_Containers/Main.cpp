#include <iostream>
#include <string>
#include <deque>
#include <string_view>
#include <array>
#include <vector>
/*

string class has performance costs

String_View doesn't have its own instance of the copy
String View is read-only (const)

Containers are collections of objects of the same type

Vectors store in contigious locations

Vectors vs Arrays:
std::vector is a template class that encapsulate a dynamic array1, stored in the heap, that grows and shrinks automatically if elements are added or removed. It provides all the hooks (begin(), end(), iterators, etc) that make it work fine with the rest of the STL. It also has several useful methods that let you perform operations that on a normal array would be cumbersome, like e.g. inserting elements in the middle of a vector (it handles all the work of moving the following elements behind the scenes).
Since it stores the elements in memory allocated on the heap, it has some overhead in respect to static arrays.
std::array is a template class that encapsulate a statically-sized array, stored inside the object itself, which means that, if you instantiate the class on the stack, the array itself will be on the stack. Its size has to be known at compile time (it's passed as a template parameter), and it cannot grow or shrink.
It's more limited than std::vector, but it's often more efficient, especially for small sizes, because in practice it's mostly a lightweight wrapper around a C-style array. However, it's more secure, since the implicit conversion to pointer is disabled, and it provides much of the STL-related functionality of std::vector and of the other containers, so you can use it easily with STL algorithms & co. Anyhow, for the very limitation of fixed size it's much less flexible than std::vector.

*/
int main()
{
	char cstr[] = "Something";
	std::cout << "Cstring: " << (void*)&cstr[0] << std::endl;	// address of first element in array

	{
		std::string str = cstr;
		std::cout << "String: " << (void*)&str[0] << std::endl;	// address of first element in array
	}

	{
		std::string_view sv = cstr;
		std::cout << "String View: " << (void*)&sv[0] << std::endl;	// address of first element in array
	}

	{
		// Contiguous
		int a[2];
		std::array<int, 5> a_int;
		std::vector<double> dv;
	}

	{
		// (push pop)
		// stack
		// lists
		// deque
	}

	{
		std::vector<double>dv;

		dv.push_back(1.0);
		dv.push_back(2.0);
		dv.push_back(3.0);
		dv.push_back(4.0);
		//std::vector<double>::iterator it = dv.begin();	// iterator for the double that points to the first element in the vector
		auto it = dv.begin();

		std::cout << *it << std::endl;	// 1

		for (; it != dv.end(); ++it)
			std::cout << *it << std::endl;	// 1, 2, 3, 4
	}

	std::cin.get();
}