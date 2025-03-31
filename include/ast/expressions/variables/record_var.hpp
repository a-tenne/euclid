#ifndef _RECORD_VAR_HPP
#define _RECORD_VAR_HPP
#include "var.hpp"
#include <memory>
namespace euclid
{
class record_var : public variable
{
public:
  record_var (std::unique_ptr<variable> &&left,
              std::unique_ptr<variable> &&right);
  void print (uint indent) const override;

private:
  std::unique_ptr<variable> m_left, m_right;
};
} // namespace euclid

#endif