#include <iostream>
#include <string>

using namespace std;

enum class Order { DESCENDING, ASCENDING };
template <typename T>
class Comparator
{
	Order m_Order;
public:
	Comparator(Order theOrder)
		: m_Order(theOrder)
	{
	}

	bool operator()(const T& a, const T& b)
	{
		if (m_Order == Order::ASCENDING)
			return a > b;
		else
			return a < b;
	}
};

template<typename T>
void display(const T* arr, size_t n)
{
	cout << arr[0];
	for (size_t i = 1; i < n; ++i)
		cout << ", " << arr[i];
	cout << endl;
}
template<typename T, typename Comp>
void bubbleSort(T* arr, size_t n, Comp cmp)
{
	for (size_t i = 0; i < n - 1; ++i)
		for (size_t j = i; j < n; ++j)
			if (cmp(arr[i], arr[j]))
			{
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}
template<typename A, typename B>
bool cmpDesc(const A& a, const B& b)
{
	return a < b;
}
template<typename A, typename B>
bool cmpAsc(const A& a, const B& b)
{
	return a > b;
}

int main()
{
	int arr[] = { 32, 5,2, -5, 65, 74, 94, 3, -4, 1 };

	bool(*funcCmp)(const int&, const int&) = cmpDesc;
/*	cout << "Sort how? (1 - Asc; 2 - Desc) ";
	int choice;
	cin >> choice;
	if (choice == 1)
		funcCmp = cmpAsc;
	else
		funcCmp = cmpDesc;*/
	Comparator<int> cmpObject(Order::ASCENDING);

	int cnt = 0;

	/// Anonymous function (Lambda function) returns a bool
	auto lambdaCmp = [&](const int& a, const int& b) -> bool
	{
		cnt++;
		return a < b;
	};

	display(arr, 10);
	bubbleSort(arr, 10, lambdaCmp);
	display(arr, 10);

	cout << "The lambda has been called " << cnt << " times" << endl;

	return 0;
}