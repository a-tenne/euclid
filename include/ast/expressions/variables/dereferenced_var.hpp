#ifndef _DEREFERENCED_VAR_HPP
#define _DEREFERENCED_VAR_HPP
#include "var.hpp"
#include <memory>
namespace euclid
{
class dereferenced_variable : public variable
{
private:
  std::unique_ptr<variable> m_var;
};
} // namespace euclid

#endif