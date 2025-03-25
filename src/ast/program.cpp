#include "program.hpp"
#include <iostream>
#include <memory>

namespace euclid
{
using std::cout, std::string, std::move;

void
program::set_name (string &&name)
{
  m_name = move (name);
}
void
program::set_block (block &&_block)
{
  m_block = move (_block);
}

void
program::print (uint indent) const
{
  print_indent (indent);
  cout << "program " << m_name << " (\n";
  m_block.print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
