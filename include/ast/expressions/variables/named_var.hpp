#ifndef _NAMED_VAR_HPP
#define _NAMED_VAR_HPP
#include "var.hpp"
#include <string>

namespace euclid
{
class named_var : public variable
{
public:
  named_var (const std::string &ident, const position &pos);
  void print (uint indent) const override;

private:
  std::string m_ident;
};
} // namespace euclid

#endif