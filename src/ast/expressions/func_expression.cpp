#include "func_expression.hpp"
#include <iostream>

namespace euclid
{
using std::vector, std::unique_ptr, std::string, std::move, std::cout;
function_expression::function_expression (
    vector<unique_ptr<expression> > &&params, const string &ident,
    const position &pos)
    : m_params (move (params)), m_ident (ident),
      expression (expression_kind::FUNC_CALL, pos)
{
}
void
function_expression::print (uint indent) const
{
  print_indent (indent);
  cout << "function_expression (\n";
  print_indent (indent + 1);
  cout << m_ident << "(\n";
  for (size_t i = 0; i < m_params.size (); ++i)
    {
      m_params[i]->print (indent + 2);
      if (i + 1 < m_params.size ())
        cout << ", ";
    }
}
} // namespace euclid
