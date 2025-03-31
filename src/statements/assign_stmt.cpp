#include "assign_stmt.hpp"
#include <iostream>

namespace euclid
{
using std::move, std::cout, std::unique_ptr;

assign_statement::assign_statement (unique_ptr<variable> &&left,
                                    unique_ptr<expression> &&right)
    : m_left (move (left)), m_right (move (right)),
      statement (statement_kind::ASGN)
{
}

void
assign_statement::print (uint indent) const
{
  print_indent (indent);
  cout << "assign_statement (\n";
  m_left->print (indent + 1);
  m_right->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid