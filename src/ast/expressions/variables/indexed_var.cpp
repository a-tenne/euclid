#include "indexed_var.hpp"
#include <iostream>
namespace euclid
{
using std::unique_ptr, std::move, std::cout;
indexed_var::indexed_var (unique_ptr<variable> &&var,
                          unique_ptr<expression> &&index)
    : variable (variable_kind::INDEXED, var->get_pos ()), m_var (move (var)),
      m_index (move (index))
{
}

void
indexed_var::print (uint indent) const
{
  print_indent (indent);
  cout << "indexed_var (\n";
  m_var->print (indent + 1);
  print_indent (indent + 1);
  cout << " [ ";
  m_index->print (indent + 1);
  print_indent (indent + 1);
  cout << " ]\n)\n";
}
} // namespace euclid
