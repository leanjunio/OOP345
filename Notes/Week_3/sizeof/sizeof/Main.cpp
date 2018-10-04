#include <iostream>


int main()
{
	/// SIZEOF
	{
		/*
			sizeof returns bytes of the value inside its parenthesis
			- Evaluated at compile time NOT RUN TIME
		*/
		std::cout << "Size of an int" << sizeof(new int) << std::endl;

		short arr[] = { 42, 54, 7, 6, 8 };
		std::cout << "total byte size of arr[]: " << sizeof(arr) << std::endl;

		// Counting the size of an element
		// NOTE: This calculation only works if the array is statically allocated arrays
		// sizeof(*ptr) shows the size only of the POINTER
		std::cout << sizeof(arr) / sizeof(arr[0]) << " elements in arr" << std::endl;

		int a = 4;
		char c = 'A';
		void* ptr_int = &a;
		void* ptr_char = &c;
		int* ptr = &a;
		std::cout << "int*: ptr to int: " << ptr << " size (bytes): " << sizeof(ptr) << std::endl;
		std::cout << "void*: ptr to char: " << ptr_char << " size (bytes): " << sizeof(ptr_char) << std::endl;
	}

	/// DECLTYPE
	{
		std::cout << "`````DECLTYPES````````" << std::endl;
		int a = 10;
		double b = 3.2;

		// evaluate the expression and use that as the type of c
		decltype(a * b) c;
		std::cout << typeid(c).name() << std::endl;
	}

	{
		char* str = nullptr;
		// if (str[0] != '\0' && str != nullptr) - WILL CRASH
		//	std::cout << str << std::endl;

		// if (str[0] != '\0' || str != nullptr) // - WILL CRASH
		//	std::cout << str << std::endl;
	}

	/*{
		int val = 10;
		std::cout << "Category: " << Category<decltype((10))>::name << std::endl;
		std::cout << "Category: " << Category<decltype((val))>::name << std::endl;
		std::cout << "Category: " << Category<decltype((std::move(val)))>::name << std::endl;
	}*/
	std::cin.get();
}