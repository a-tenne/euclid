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
  literal_expression (
      const std::variant<int, float, bool, std::string> &literal,
      const position &pos);
  void print (void) const override;
  const std::variant<int, float, bool, std::string> &get_literal (void) const;

private:
  std::variant<int, float, bool, std::string> m_literal;

  void print_variant (void) const;
};
} // namespace euclid

#endif