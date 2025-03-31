#ifndef _NAMED_VAR_HPP
#define _NAMED_VAR_HPP
#include "token.hpp"
#include "var.hpp"
#include <string>

namespace euclid
{
class named_var : public variable
{
public:
  named_var (ident_token &tok);
  void print (uint indent) const override;

private:
  std::string m_ident;
};
} // namespace euclid

#endif