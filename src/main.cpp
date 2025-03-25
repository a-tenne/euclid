#include "parser.hpp"
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
  auto parser = euclid::parser ();
  parser.parse_file (argv[1]);
  parser.print_program ();
}
