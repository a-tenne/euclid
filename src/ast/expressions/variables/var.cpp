#include "var.hpp"

namespace euclid
{

variable::variable (variable_kind kind, const position &pos)
    : expression (expression_kind::VAR, pos), m_kind (kind)
{
}

variable_kind
variable::get_kind (void) const
{
  return m_kind;
}
} // namespace euclid
