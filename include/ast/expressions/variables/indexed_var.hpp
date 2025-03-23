#ifndef _INDEXED_VAR_HPP
#define _INDEXED_VAR_HPP
#include "var.hpp"
#include <memory>
namespace euclid
{
class indexed_var : public variable
{
private:
  std::unique_ptr<variable> m_var;
  std::unique_ptr<expression> m_index;
};

} // namespace euclid

#endif