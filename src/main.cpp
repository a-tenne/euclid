#include "lexer.hpp"
#include <iostream>

int
main (int argc, char const *argv[])
{
  if (argc != 2)
    {
      std::cerr << "No input file specified. Usage: " << argv[0]
                << " <input-file>\n";
      exit (1);
    }
  auto lexer = euclid::lexer ();
  lexer.read_file (argv[1]);
  lexer.print_remaining ();
}
