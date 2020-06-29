#if !defined(_MONKEY_TOKEN)
#define _MONKEY_TOKEN

#include <iostream>

typedef std::string token_type;
typedef std::string token_literal;

struct token
{
  token_type token;
  token_literal literal;
};

const token_type ILLEGAL = "ILLEGAL";
const token_type END_OF_FILE = "EOF";

// Identifiers + literals
const token_type IDENT = "IDENT";
const token_type INT = "INT";

// Operators
const token_type ASSIGN = "=";
const token_type PLUS = "+";
const token_type MINUS = "-";
const token_type BANG = "!";
const token_type SLASH = "/";
const token_type ASTERISK = "*";

const token_type LT = "<";
const token_type GT = ">";

// Delimiters
const token_type COMMA = ",";
const token_type SEMICOLON = ";";

const token_type LPAREN = "(";
const token_type RPAREN = ")";
const token_type LBRACE = "{";
const token_type RBRACE = "}";

// Keywords
const token_type FUNCTION = "FUNCTION";
const token_type LET = "LET";

#endif // _MONKEY_TOKEN