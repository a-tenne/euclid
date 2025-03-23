#include "unary_expression.hpp"
#include <iostream>
namespace euclid
{
using std::unique_ptr, std::move, std::cout;
unary_expression::unary_expression (unary_operator op,
                                    unique_ptr<expression> right,
                                    const position &pos)
    : m_op (op), m_right (move (right)),
      expression (expression_kind::UNARY, pos)
{
}

const expression &
unary_expression::get_right (void) const
{
  return *m_right;
}

void
unary_expression::print (uint indent) const
{
  print_indent (indent);
  cout << "unary_expression (\n";
  print_indent (indent + 1);
  switch (m_op)
    {
    case unary_operator::MINUS:
      cout << '-';
      break;
    case unary_operator::NOT:
      cout << "not";
      break;
    case unary_operator::PLUS:
      cout << '+';
      break;
    }
  cout << ' ';
  m_right->print (indent + 1);
  cout << ")\n";
}

} // namespace euclid
