#ifndef _RECORD_VAR_HPP
#define _RECORD_VAR_HPP
#include "var.hpp"
#include <memory>
#include <string>
namespace euclid
{
class record_var : public variable
{
public:
  record_var (const std::string &field, std::unique_ptr<variable> var,
              const position &pos);

private:
  std::unique_ptr<variable> m_var;
  std::string m_field;
};
} // namespace euclid

#endif