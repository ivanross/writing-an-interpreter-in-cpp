#include "repl.hpp"

#define PROMPT ">> "

void repl::start()
{
  while (true)
  {
    std::cout << PROMPT;

    std::string line;
    std::getline(std::cin, line);

    lexer l = build_lexer(line);
    token t;
    do
    {
      t = l.next_token();

      std::cout << "{Type: " << t.token << ",\tLiteral: " << t.literal << "}\n";
    } while (t.token != END_OF_FILE);
  }
}
