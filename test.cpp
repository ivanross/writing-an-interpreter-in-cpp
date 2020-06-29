#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "monkey/lexer.hpp"

int main()
{
  std::ifstream t("test.monkey");
  std::string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

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

  for (int i = 0; i < 36; i++)
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