#ifndef _NAMED_var_HPP
#define _NAMED_var_HPP
#include "var.hpp"
#include <string>

namespace euclid
{
class named_variable : public variable
{
private:
  std::string m_ident;
};
} // namespace euclid

#endif