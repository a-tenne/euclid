#include "deref_var.hpp"
#include <iostream>

namespace euclid
{
using std::unique_ptr, std::move, std::cout;
deref_var::deref_var (std::unique_ptr<variable> var, const position &pos)
    : m_var (move (var)), variable (variable_kind::DEREF, pos)
{
}

void
deref_var::print (uint indent) const
{
  print_indent (indent);
  cout << "deref_var (\n";
  m_var->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
