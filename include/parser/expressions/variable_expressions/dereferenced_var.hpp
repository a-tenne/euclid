#ifndef _DEREFERENCED_VAR_HPP
#define _DEREFERENCED_VAR_HPP
#include "var_access.hpp"
#include <memory>
namespace euclid
{
class dereferenced_variable
{
private:
  std::unique_ptr<variable_access> m_var;
};
} // namespace euclid

#endif