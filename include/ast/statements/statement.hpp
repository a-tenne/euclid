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
  statement () = default;
  statement (statement_kind kind, int line);

private:
  statement_kind m_kind;
  int m_line;
};
} // namespace euclid

#endif