#ifndef _STATEMENT_HPP
#define _STATEMENT_HPP
#include "ast_node.hpp"

namespace euclid
{

enum class statement_kind
{
  COMPOUND,
  ASGN,
  EMPTY,
  PROC,
  GOTO,
  REPEAT,
  WHILE,
  FOR,
  IF,
  CASE,
  WITH,
};

class statement : public ast_node
{
public:
  statement () = delete;
  statement (statement_kind kind);

  statement_kind
  get_kind ()
  {
    return m_kind;
  }

protected:
  statement_kind m_kind;
};
} // namespace euclid

#endif