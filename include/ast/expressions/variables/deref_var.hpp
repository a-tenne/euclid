#ifndef _DEREF_VAR_HPP
#define _DEREF_VAR_HPP
#include "var.hpp"
#include <memory>
namespace euclid
{
class deref_var : public variable
{
public:
  deref_var (std::unique_ptr<variable> var, const position &pos);
  void print (uint indent) const override;

private:
  std::unique_ptr<variable> m_var;
};
} // namespace euclid

#endif