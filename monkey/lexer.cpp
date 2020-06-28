#include "lexer.hpp"

// LEXER ------------------------------------------------------------

void lexer::read_char()
{
  ch = read_position >= input.length() ? 0 : input.at(read_position);
  position = read_position++;
}

token lexer::next_token()
{
  token tok;
  switch (ch)
  {
  case '=':
    tok = new_token(ASSIGN, ch);
    break;
  case '+':
    tok = new_token(PLUS, ch);
    break;
  case ',':
    tok = new_token(COMMA, ch);
    break;
  case ';':
    tok = new_token(SEMICOLON, ch);
    break;
  case '(':
    tok = new_token(LPAREN, ch);
    break;
  case ')':
    tok = new_token(RPAREN, ch);
    break;
  case '{':
    tok = new_token(LBRACE, ch);
    break;
  case '}':
    tok = new_token(RBRACE, ch);
    break;
  case 0:
    tok.token = EOF;
    tok.literal = "";
    break;
  default:
    return new_token(ILLEGAL, ch);
  }

  read_char();
  return tok;
}

// Utils ------------------------------------------------------------

lexer build_lexer(std::string input)
{
  lexer res = {input, 0, 0, 0};
  res.read_char();
  return res;
}

token new_token(token_type type, char ch)
{
  std::string literal(1, ch);
  token tok = {type, literal};
  return tok;
}
