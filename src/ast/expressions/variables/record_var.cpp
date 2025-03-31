#include "record_var.hpp"
#include <iostream>

namespace euclid
{
using std::cout, std::unique_ptr, std::move;

record_var::record_var (std::unique_ptr<variable> &&left,
                        std::unique_ptr<variable> &&right)
    : m_left (move (left)), m_right (move (right)),
      variable (variable_kind::REC_FIELD, m_left->get_pos ())
{
}

void
record_var::print (uint indent) const
{
  print_indent (indent);
  cout << "record_var (\n";
  m_left->print (indent + 1);
  m_right->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
