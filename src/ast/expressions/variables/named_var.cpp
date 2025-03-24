#include "named_var.hpp"
#include <iostream>

namespace euclid
{
using std::string, std::cout;
named_var::named_var (const string &ident, const position &pos)
    : m_ident (ident), variable (variable_kind::NAMED, pos)
{
}

void
named_var::print (uint indent) const
{
  print_indent (indent);
  cout << "named_var (\n";
  print_indent (indent + 1);
  cout << m_ident << '\n';
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
