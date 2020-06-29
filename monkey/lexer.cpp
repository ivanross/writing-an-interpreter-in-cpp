#include "lexer.hpp"

// LEXER ------------------------------------------------------------

void lexer::read_char()
{
  ch = read_position >= input.length() ? 0 : input.at(read_position);
  position = read_position++;
}

void lexer::skip_whitespace()
{
  while (is_whitespace(ch))
    read_char();
}

token_literal lexer::read_identifier()
{
  int pos = position;
  while (is_letter(ch))
    read_char();

  std::string ident(&input[pos], &input[position]);
  return ident;
}

token_literal lexer::read_number()
{
  int pos = position;
  while (is_number(ch))
    read_char();

  std::string ident(&input[pos], &input[position]);
  return ident;
}

token lexer::next_token()
{
  token tok;

  skip_whitespace();

  switch (ch)
  {
  case '=':
    tok = new_token(ASSIGN, ch);
    break;
  case '+':
    tok = new_token(PLUS, ch);
    break;
  case '-':
    tok = new_token(MINUS, ch);
    break;
  case '*':
    tok = new_token(ASTERISK, ch);
    break;
  case '/':
    tok = new_token(SLASH, ch);
    break;
  case '!':
    tok = new_token(BANG, ch);
    break;
  case '<':
    tok = new_token(LT, ch);
    break;
  case '>':
    tok = new_token(GT, ch);
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
    if (is_letter(ch))
    {
      tok.literal = read_identifier();
      tok.token = lookup_ident(tok.literal);
      return tok;
    }
    else if (is_number(ch))
    {
      tok.token = INT;
      tok.literal = read_number();
      return tok;
    }
    {
      tok = new_token(ILLEGAL, ch);
    }
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

inline bool is_letter(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

inline bool is_number(char c)
{
  return c >= '0' && c <= '9';
}

inline bool is_whitespace(char c)
{
  return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

token_type lookup_ident(token_literal &literal)
{
  if (literal == "let")
    return LET;
  if (literal == "fn")
    return FUNCTION;

  return IDENT;
}