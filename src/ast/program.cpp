#include "program.hpp"
#include <iostream>
#include <memory>

namespace euclid
{
using std::cout, std::string, std::move, std::unique_ptr;

void
program::set_name (string &&name)
{
  m_name = move (name);
}
void
program::set_block (unique_ptr<block> &&inner)
{
  m_inner = move (inner);
}

void
program::print (uint indent) const
{
  print_indent (indent);
  cout << "program " << m_name << " (\n";
  m_inner->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
