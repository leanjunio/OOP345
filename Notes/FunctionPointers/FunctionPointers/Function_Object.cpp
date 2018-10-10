// Function Objects
// Function_Object.cpp

#include <iostream>

// order options
enum class Order
{
	ascending,
	descending
};

// order comparison
template <typename T>
class Compare
{
	Order order;
public:
	Compare(Order o)
		: order(o) 
	{
	}

	template <typename T>
	bool operator()(T& a, T& b) const 
	{
		return order == Order::ascending ? a > b : a < b;
	}
};

// Bubble Sort
template <typename T>
void sort(T* a, int n, const Compare<T>& comp)
{
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (comp(a[j], a[j + 1])) {
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void display(T* a, int n) 
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

int main() {
	int a[] = { 1, 5, 2, 3, 6, 7, 2 };
	int n = sizeof a / sizeof(int);

	sort(a, n, Compare<int>(Order::ascending));
	display(a, n);

	sort(a, n, Compare<int>(Order::descending));
	display(a, n);
}