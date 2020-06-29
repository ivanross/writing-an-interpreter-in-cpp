#include <iostream>
#include "monkey/repl.hpp"

int main()
{
  std::cout << "This is the Monkey programming language.\n"
            << "Feel free to type in commands\n";
  repl::start();
  return 0;
}