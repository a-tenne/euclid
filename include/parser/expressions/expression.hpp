#ifndef _EXPRESSION_HPP
#define _EXPRESSION_HPP
#include "ast_node.hpp"
#include "position.hpp"

namespace euclid
{

/* enum class expression_kind
    {
      BINARY,
      UNARY,
      VARIABLE,
      FUNC_CALL,
      SET_CONSTR,
      LIT,
    }; */

class expression : public ast_node
{
protected:
  position m_pos;
};

} // namespace euclid

#endif