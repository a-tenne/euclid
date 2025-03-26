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
private:
  std::string m_left;
  std::unique_ptr<expression> m_right;
};

} // namespace euclid

#endif