#ifndef _FUNC_EXPRESSION_HPP
#define _FUNC_EXPRESSION_HPP
#include "expression.hpp"
#include <memory>
#include <vector>

namespace euclid
{
class function_expression : public expression
{
public:
  function_expression (std::vector<std::unique_ptr<expression> > &&params,
                       const std::string &ident, const position &pos);
  void print (uint indent) const override;

private:
  std::string m_ident;
  std::vector<std::unique_ptr<expression> > m_params;
};
} // namespace euclid

#endif