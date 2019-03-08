#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  // get arguments
  std::cout << "Command line: ";
  for (int i = 0; i < argc; ++i)
    std::cout << argv[i] << ' ';
  std::cout << std::endl;

  
   
  return 0;
}