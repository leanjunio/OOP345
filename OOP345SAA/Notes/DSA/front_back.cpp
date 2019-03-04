#include <iostream>
#include <vector>
#include <stack>
#include <deque>

int main()
{
  /*
    NOTE:
    - FRONT starts at index 0
    - BACK starts at size()
  */
  std::vector<int> my_vector {1, 2, 3};
  std::deque<int> my_deque = {3, 2, 1};
  std::stack<int> my_stack;

  std::cout << "Vector front: " << my_vector.front() << std::endl;
  std::cout << "Vector back: " << my_vector.back() << std::endl;
  std::cout << "Pushing to the back()... " << std::endl;
  my_vector.push_back(100);

  for(auto&& i : my_vector)
    std::cout << i << ' ';

  std::cout << std::endl;
  
  std::cout << "========" << std::endl;
  std::cout << "Deque front: " << my_deque.front() << std::endl;
  std::cout << "Deque back: " << my_deque.back() << std::endl;
  std::cout << "Pushing to the front()... " << std::endl;
  my_deque.push_front(100);

  for(auto&& i : my_deque)
    std::cout << ' ';    
  
  return 0;
}