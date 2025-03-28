#include "assign_stmt.hpp"
#include <iostream>

namespace euclid
{
using std::move, std::cout, std::string;

assign_statement::assign_statement (string &&left)
    : statement (statement_kind::ASGN), m_left (move (left))
{
}

void
assign_statement::print (uint indent) const
{
  print_indent (indent);
  cout << "assign_statement (\n";
  print_indent (indent + 1);
  cout << "identifier: " << m_left << '\n';
  m_right->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid