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
  set_expression (
      const std::initializer_list<std::unique_ptr<expression> > &list);

private:
  std::vector<std::unique_ptr<expression> > m_list;
};
} // namespace euclid

#endif