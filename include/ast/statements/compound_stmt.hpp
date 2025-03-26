#ifndef _COMPOUND_STMT_HPP
#define _COMPOUND_STMT_HPP
#include "statement.hpp"
#include <memory>
#include <vector>

namespace euclid
{
class compound_statement : public statement
{
public:
  compound_statement () = default;
  void print (uint indent) const override;

private:
  std::vector<std::unique_ptr<statement> > m_inner;
};
} // namespace euclid

#endif