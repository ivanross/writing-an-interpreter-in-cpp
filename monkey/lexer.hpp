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
  char peak_char();
  void skip_whitespace();
  token_literal read_identifier();
  token_literal read_number();
  token next_token();
};

lexer build_lexer(std::string input);
token new_token(token_type, char);
inline bool is_letter(char c);
inline bool is_number(char c);
inline bool is_whitespace(char c);
token_type lookup_ident(token_literal &literal);

#endif // _MONKEY_LEXER_H
