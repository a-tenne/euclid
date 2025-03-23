#ifndef _EXPRESSION_HPP
#define _EXPRESSION_HPP
#include "ast_node.hpp"
#include "position.hpp"

namespace euclid
{

enum class expression_kind
{
  BINARY,
  UNARY,
  VAR,
  FUNC_CALL,
  SET_CONSTR,
  LITERAL,
};

class expression : public ast_node
{
public:
  expression () = delete;
  expression (expression_kind kind, const position &pos);
  const position &get_pos (void) const;
  expression_kind get_kind (void) const;

protected:
  expression_kind m_kind;
  position m_pos;
};

} // namespace euclid

#endif