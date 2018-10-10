/*

Arrays of Pointers to Functions

If several functions share the same return types and parameters, we may store their addresses in an array

Format:
return-type (*identifier[n])(params) = { initialization-list };

n: the number of elements in the array
*/

// Function Pointers
 // array_function_pointers.cpp

#include <iostream>

// ascending order comparison
template <typename T>
bool ascending(T a, T b) { return a > b; }

// descending order comparison
template <typename T>
bool descending(T a, T b) { return a < b; }

// bubble sort
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

	// This is the function pointer with the identifier criterion
	bool(*criterion[2])(int, int) = { ascending, descending };
	int n = sizeof a / sizeof(int);

	for (int i = 0; i < 2; i++) {
		sort(a, n, criterion[i]);
		display(a, n);
	}
}