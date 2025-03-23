#include "expression.hpp"

namespace euclid
{

expression::expression (expression_kind kind, const position &pos)
    : m_pos (pos), m_kind (kind)
{
}

const position &
expression::get_pos (void) const
{
  return m_pos;
}

expression_kind
expression::get_kind (void) const
{
  return m_kind;
}

} // namespace euclid
