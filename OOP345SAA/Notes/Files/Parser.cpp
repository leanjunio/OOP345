#include <fstream>
#include "Parser.h"

// Constructor
// 
Parser::Parser(const char* filename, char delimiter)
  : m_delimiter{delimiter}
{
  size_t numbers = {0};
  std::string word  = {""};
  size_t number = {0};

  std::ifstream fs("filename", std::ifstream::in);
  

}