#ifndef _LIT_EXPRESSION_HPP
#define _LIT_EXPRESSION_HPP
#include "expression.hpp"
#include "token.hpp"
#include <memory>
#include <variant>

namespace euclid
{

enum class literal_kind
{
  INTEGER,
  REAL,
  BOOLEAN,
  STRING
};
class literal_expression : public expression
{

public:
  literal_expression (const literal_token &lit_token);
  void print (uint indent) const override;

  const std::variant<int, float, bool, std::string> &
  get_literal () const
  {
    return m_literal;
  }

  literal_kind
  get_kind () const
  {
    return m_kind;
  }

private:
  std::variant<int, float, bool, std::string> m_literal;
  literal_kind m_kind;

  void print_variant () const;
};
} // namespace euclid

#endif