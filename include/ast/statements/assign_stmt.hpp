#ifndef _ASSIGN_STMT_HPP
#define _ASSIGN_STMT_HPP
#include "expression.hpp"
#include "statement.hpp"
#include <memory>
#include <string>

namespace euclid
{
class assign_statement : public statement
{
public:
  assign_statement (std::string &&left);
  void print (uint indent) const override;

  const std::string &
  get_left () const
  {
    return m_left;
  }
  void
  set_right (std::unique_ptr<expression> &&right)
  {
    m_right = std::move (right);
  }

private:
  std::string m_left;
  std::unique_ptr<expression> m_right;
};

} // namespace euclid

#endif