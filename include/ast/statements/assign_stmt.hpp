#ifndef _ASSIGN_STMT_HPP
#define _ASSIGN_STMT_HPP
#include "expression.hpp"
#include "statement.hpp"
#include "var.hpp"
#include <memory>

namespace euclid
{
class assign_statement : public statement
{
public:
  assign_statement (std::unique_ptr<variable> &&left,
                    std::unique_ptr<expression> &&right);
  void print (uint indent) const override;

  const variable &
  get_left () const
  {
    return *m_left;
  }

  void
  set_left (std::unique_ptr<variable> &&left)
  {
    m_left = std::move (left);
  }

  void
  set_right (std::unique_ptr<expression> &&right)
  {
    m_right = std::move (right);
  }

private:
  std::unique_ptr<variable> m_left;
  std::unique_ptr<expression> m_right;
};

} // namespace euclid

#endif