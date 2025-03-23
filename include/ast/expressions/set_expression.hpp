#ifndef _SET_EXPRESSION_HPP
#define _SET_EXPRESSION_HPP
#include "expression.hpp"
#include <initializer_list>
#include <memory>
#include <vector>

namespace euclid
{
class set_expression : public expression
{
  set_expression (std::vector<std::unique_ptr<expression> > &&list,
                  const position &pos);
  void print (uint indent) const override;

private:
  std::vector<std::unique_ptr<expression> > m_list;
};
} // namespace euclid

#endif