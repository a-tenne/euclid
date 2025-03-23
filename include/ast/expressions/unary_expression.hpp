#ifndef _UNARY_EXPRESSION_HPP
#define _UNARY_EXPRESSION_HPP
#include "expression.hpp"
#include <memory>

namespace euclid
{
enum class unary_operator
{
  PLUS,
  MINUS,
  NOT
};

class unary_expression : public expression
{
  unary_expression (unary_operator op, std::unique_ptr<expression> right,
                    const position &pos);
  const expression &get_right (void) const;
  void print (uint indent) const override;

private:
  std::unique_ptr<expression> m_right;
  unary_operator m_op;
};
} // namespace euclid

#endif