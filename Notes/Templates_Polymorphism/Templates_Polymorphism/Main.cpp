#include <iostream>
#include <typeinfo>
#include <string>

// Templates must be accessible upon compile time so put them in the header
template<typename T, int SIZE = 5>
T calculateSum(T* arr)
{
	T result = 0;
	for (size_t i = 0; i < SIZE; i++)
		result += arr[i];
	// result /= SIZE;
	return result;
}

template<typename T, typename T2>
double calculateAvg(T first, T2 second)
{
	T result = first + second;
	return result;
}

// class templates
template<typename T>
class Foo
{
	T m_Value;
	static int m_Count;	// must be initialized outside of the class
public:
	Foo()
	{
		m_Value = 0;
		m_Count++;
	}

	void display() const
	{
		std::cout << typeid(*this).name() << " ";
		std::cout << m_Value << std::endl;
	}
};

template <>
int Foo<double>::m_Count = 100;

int main()
{
	Foo<float> f_f;
	f_f.display();

	Foo<short> f_s;
	f_s.display();

	int arr[] = { 1,2,3,4,5 };
	std::cout << calculateSum<int, 5>(arr) << std::endl;
	/*std::cout << calculateSum<int, int, double>(32, 1) << std::endl;
	std::cout << calculateSum<std::string>("Hello", "World!") << std::endl;
	std::cout << calculateSum<double>(32.23, 2.54) << std::endl;
	std::cout << calculateSum<int>(32, 2) << std::endl;*/
	std::cin.get();
}