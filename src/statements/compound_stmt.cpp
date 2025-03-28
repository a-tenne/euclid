#include "compound_stmt.hpp"
#include <iostream>

namespace euclid
{
using std::cout;

compound_statement::compound_statement ()
    : statement (statement_kind::COMPOUND), m_inner ()
{
}

void
compound_statement::print (uint indent) const
{
  print_indent (indent);
  cout << "compound_statement (\n";
  for (auto &ptr : m_inner)
    ptr->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
