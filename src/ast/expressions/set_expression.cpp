#include "set_expression.hpp"
#include <iostream>
namespace euclid
{
using std::cout, std::move, std::vector;
set_expression::set_expression (vector<std::unique_ptr<expression> > &&list,
                                const position &pos)
    : m_list (move (list)), expression (expression_kind::SET_CONSTR, pos)
{
}

void
set_expression::print (uint indent) const
{
  print_indent (indent);
  cout << "set_expression (\n";
  print_indent (indent + 1);
  cout << "[\n";
  for (size_t i = 0; i < m_list.size (); ++i)
    {
      m_list[i]->print (indent + 1);
      if (i + 1 < m_list.size ())
        cout << ", ";
    }
  print_indent (indent + 1);
  cout << "]\n";
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
