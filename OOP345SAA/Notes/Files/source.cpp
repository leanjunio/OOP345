#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
  char str[1025];  // create a char of 1025 elements
  char* p = str;   // store the address of 'str' to p

  // Create file and open from 'arg[1]'
  std::ifstream f(argv[1], std::ios::in | std::ios::binary);

  while(f)  // while failbit is != true
    f.read(p++, 1); // extract one character from the stream and store in p++ (&str)

  *--p = '\0';  // sets the very last part of the string as null
  std::cout << str << std::endl; // print out a string.

  return 0;
}
