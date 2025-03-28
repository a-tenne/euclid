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
  compound_statement ();
  compound_statement (int line);
  void print (uint indent) const override;

  void
  append (std::unique_ptr<statement> &&stmt)
  {
    m_inner.push_back (std::move (stmt));
  }

private:
  std::vector<std::unique_ptr<statement> > m_inner;
};
} // namespace euclid

#endif