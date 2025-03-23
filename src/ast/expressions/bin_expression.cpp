#include "bin_expression.hpp"
#include <iostream>
#define ENTRY(op, str) { binary_operator::op, str }

namespace euclid
{
using std::string, std::unique_ptr, std::move, std::cout;
const std::unordered_map<binary_operator, string>
    binary_expression::m_print_lookup
    = { ENTRY (PLUS, "+"),  ENTRY (MINUS, "-"), ENTRY (ASTERISK, "*"),
        ENTRY (SLASH, "/"), ENTRY (DIV, "div"), ENTRY (MOD, "mod"),
        ENTRY (AND, "and"), ENTRY (OR, "or"),   ENTRY (EQ, "="),
        ENTRY (NE, "<>"),   ENTRY (LT, "<"),    ENTRY (GT, ">"),
        ENTRY (LE, "<="),   ENTRY (GE, ">="),   ENTRY (IN, "in") };

binary_expression::binary_expression (unique_ptr<expression> left,
                                      unique_ptr<expression> right,
                                      const position &pos)
    : m_left (move (left)), m_right (move (right)),
      expression (expression_kind::BINARY, pos)
{
}

binary_operator
binary_expression::get_op (void) const
{
  return m_op;
}

const expression &
binary_expression::get_left (void) const
{
  return *m_left;
}
const expression &
binary_expression::get_right (void) const
{
  return *m_right;
}

void
binary_expression::print (uint indent) const
{
  print_indent (indent);
  cout << "binary_expression (\n";
  m_left->print (indent + 1);
  m_right->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
