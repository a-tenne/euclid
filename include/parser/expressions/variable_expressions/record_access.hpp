#ifndef _RECORD_VAR_HPP
#define _RECORD_VAR_HPP
#include "var_access.hpp"
#include <memory>
#include <string>
namespace euclid
{
class record_var : public variable_access
{
private:
  std::unique_ptr<variable_access> m_var;
  std::string m_field;
};
} // namespace euclid

#endif