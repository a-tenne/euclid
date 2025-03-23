#include "unary_expression.hpp"

namespace euclid
{
using std::unique_ptr, std::move;
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

} // namespace euclid
