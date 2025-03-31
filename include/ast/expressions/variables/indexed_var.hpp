#ifndef _INDEXED_VAR_HPP
#define _INDEXED_VAR_HPP
#include "var.hpp"
#include <memory>
namespace euclid
{
class indexed_var : public variable
{
public:
  indexed_var (std::unique_ptr<variable> &&var,
               std::unique_ptr<expression> &&index);
  void print (uint indent) const override;

private:
  std::unique_ptr<variable> m_var;
  std::unique_ptr<expression> m_index;
};

} // namespace euclid

#endif