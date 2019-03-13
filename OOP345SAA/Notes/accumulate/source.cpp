#include <iostream>
#include <numeric>
#include <vector>

int main() {
  
	std::vector<int> values;

	for (int i = 0; i < 5; ++i)
		values.push_back(i);

	auto total = std::accumulate(values.begin(), values.end(), 0, [](auto& a, auto& b) {
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    return a + b;
  });

  std::cout << total;

  return 0;
}