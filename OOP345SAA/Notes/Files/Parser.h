#ifndef _PARSER_H
#define _PARSER_H

#include <string>

class Parser
{
  char m_delimiter;
  std::string m_record;
public:
  Parser(const char*, char);
};

#endif