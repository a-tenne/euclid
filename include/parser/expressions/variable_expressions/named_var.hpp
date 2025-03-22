#ifndef _NAMED_var_HPP
#define _NAMED_var_HPP
#include "expression.hpp"
#include <string>

namespace euclid
{
class named_variable : public expression
{
private:
  std::string m_ident;
};
} // namespace euclid

#endif