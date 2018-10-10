// Function Pointers
// Function_Pointers.cpp

#include <iostream>

// Ascending comparison
template <typename T>
bool ascending(T a, T b) { return a > b; }

// Descending comparison
template <typename T>
bool descending(T a, T b) { return a < b; }

// Bubble Sort
// NOTE: bool(*comp)(T, T) is a function pointer
template <typename T>
void sort(T* a, int n, bool(*comp)(T, T)) {
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
void display(T* a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

int main() {
	int a[] = { 1, 5, 2, 3, 6, 7, 2 };
	int n = sizeof a / sizeof(int);

	sort(a, n, ascending<int>);
	display(a, n);
	sort(a, n, descending<int>);
	display(a, n);

	std::cin.get();
}
