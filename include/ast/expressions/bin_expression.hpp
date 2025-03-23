#ifndef _BIN_EXPRESSION_HPP
#define _BIN_EXPRESSION_HPP
#include "expression.hpp"
#include <memory>
#include <unordered_map>

namespace euclid
{

enum class binary_operator
{
  PLUS,
  MINUS,
  ASTERISK,
  SLASH,
  DIV,
  MOD,
  AND,
  OR,
  EQ,
  NE,
  LT,
  GT,
  LE,
  GE,
  IN
};

class binary_expression : public expression
{
public:
  binary_expression (std::unique_ptr<expression> left,
                     std::unique_ptr<expression> right, const position &pos);
  const expression &get_left (void) const;
  const expression &get_right (void) const;
  binary_operator get_op (void) const;
  void print (uint indent) const override;

private:
  std::unique_ptr<expression> m_left, m_right;
  binary_operator m_op;
  static const std::unordered_map<binary_operator, std::string> m_print_lookup;
};
} // namespace euclid

#endif