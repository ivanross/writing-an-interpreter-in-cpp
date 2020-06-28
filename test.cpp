#include <iostream>
#include "monkey/lexer.hpp"

template <class T>
unsigned int arrlen(T *arr)
{
  return *(&arr + 1) - arr;
}

int main()
{
  const std::string input = "=+(){},;";

  token out[] = {
      {ASSIGN, "="},
      {PLUS, "+"},
      {LPAREN, "("},
      {RPAREN, ")"},
      {LBRACE, "{"},
      {RBRACE, "}"},
      {COMMA, ","},
      {SEMICOLON, ";"}};

  lexer l = build_lexer(input);

  for (int i = 0; i < arrlen(out); i++)
  {
    token expected = out[i];
    token tok = l.next_token();

    if (expected.token != tok.token)
    {
      std::cerr << "test[" << i << "]: tokentype wrong. "
                << "Expected=" << expected.token << ", Got=" << tok.token << std::endl;
      std::terminate();
    }

    if (expected.literal != tok.literal)
    {
      std::cerr << "test[" << i << "]: token literal wrong. "
                << "Expected=" << expected.literal << ", Got=" << tok.literal << std::endl;
      std::terminate();
    }
  }

  return 0;
}