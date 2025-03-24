#include "program.hpp"
#include <iostream>

namespace euclid
{
using std::cout, std::string;
program::program (const string &name, const block &_block)
    : m_name (name), m_block (_block)
{
}

void
program::print (uint indent = 0) const
{
  print_indent (indent);
  cout << "program " << m_name << " (\n";
  m_block.print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
