#include "named_var.hpp"
#include <iostream>
#include <memory>

namespace euclid
{
using std::move, std::cout;
named_var::named_var (ident_token &tok)
    : m_ident (move (tok.get_name ())),
      variable (variable_kind::NAMED, tok.get_pos ())
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
