#include <iostream>
#include "monkey/lexer.hpp"

template <class T>
unsigned int arrlen(T *arr)
{
  return *(&arr + 1) - arr;
}

int main()
{
  const std::string input = "let     five = 5;\n"
                            "let ten = 10;\n"
                            "\n"
                            "let add = fn(x,y) {\n"
                            "    x + y;\n"
                            "};\n"
                            "\n"
                            "let result = add(five,ten);\n";

  std::cout << input;

  token out[] = {
      {LET, "let"},
      {IDENT, "five"},
      {ASSIGN, "="},
      {INT, "5"},
      {SEMICOLON, ";"},

      {LET, "let"},
      {IDENT, "ten"},
      {ASSIGN, "="},
      {INT, "10"},
      {SEMICOLON, ";"},

      {LET, "let"},
      {IDENT, "add"},
      {ASSIGN, "="},
      {FUNCTION, "fn"},
      {LPAREN, "("},
      {IDENT, "x"},
      {COMMA, ","},
      {IDENT, "y"},
      {RPAREN, ")"},
      {LBRACE, "{"},

      {IDENT, "x"},
      {PLUS, "+"},
      {IDENT, "y"},
      {SEMICOLON, ";"},

      {RBRACE, "}"},
      {SEMICOLON, ";"},

      {LET, "let"},
      {IDENT, "result"},
      {ASSIGN, "="},
      {IDENT, "add"},
      {LPAREN, "("},
      {IDENT, "five"},
      {COMMA, ","},
      {IDENT, "ten"},
      {RPAREN, ")"},
      {SEMICOLON, ";"},
  };

  lexer l = build_lexer(input);

  for (int i = 0; i < arrlen(out); i++)
  {
    token expected = out[i];
    token tok = l.next_token();

    if (expected.token != tok.token)
    {
      std::cerr << "test[" << i << "]: tokentype wrong. "
                << "Expected=" << expected.token << ", Got=" << tok.token << "[literal=\"" << tok.literal << "\"]" << std::endl;
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