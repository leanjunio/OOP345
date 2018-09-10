#include <iostream>
#include <iomanip>

void dumpMemory(void* p, size_t size) 
{
	unsigned char* pChar = static_cast<unsigned char*>(p);
	std::cout << std::setfill('0') << std::hex;

	for (auto i = 0u; i < size; i++)
		std::cout << " " << std::setw(2) << (unsigned int)pChar[i];

	std::cout << std::setfill(' ') << std::dec << std::endl;
}

//void rangeFor(int* a)
//{
//	for (auto& i : a)
//		std::cout << i << std::endl;
//}

int main()
{
	int a[] = {10, 2345};
	for (auto& i : a)
		std::cout << "0x" << &i << " " << i << std::endl;
	
	// References
	{
		int val;
		int&& ref = 10;
		int& a = val;		// L value reference


		val = a;
	}

	std::cin.get();
}

