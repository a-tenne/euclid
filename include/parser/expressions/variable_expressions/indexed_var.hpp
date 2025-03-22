#ifndef _INDEXED_VAR_HPP
#define _INDEXED_VAR_HPP
#include "var_access.hpp"
#include <memory>
namespace euclid
{
class indexed_var : public variable_access
{
private:
  std::unique_ptr<variable_access> m_var;
  std::unique_ptr<expression> m_index;
};

} // namespace euclid

#endif