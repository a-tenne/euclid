#ifndef _LIT_EXPRESSION_HPP
#define _LIT_EXPRESSION_HPP
#include "expression.hpp"
#include "token.hpp"
#include <variant>

namespace euclid
{

class literal_expression : public expression
{

public:
  literal_expression (std::variant<int, float, std::string> m_literal);
  void print (void) override;
  const std::variant<int, float, std::string> &get_literal (void) const;

private:
  std::variant<int, float, std::string> m_literal;
};
} // namespace euclid

#endif