#if !defined(_MONKEY_LEXER_H)
#define _MONKEY_LEXER_H

#include <iostream>
#include "token.hpp"

struct lexer
{
  std::string input;
  int position;
  int read_position;
  char ch;

  void read_char();
  token next_token();
};

lexer build_lexer(std::string input);
token new_token(token_type, char);

#endif // _MONKEY_LEXER_H
