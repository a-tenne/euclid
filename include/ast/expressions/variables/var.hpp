#ifndef _VAR_HPP
#define _VAR_HPP
#include "expression.hpp"
namespace euclid
{

enum class variable_kind
{
  INDEXED,
  REC_FIELD,
  NAMED,
  DEREF
};

class variable : public expression
{
public:
  variable () = delete;
  variable (variable_kind kind, const position &pos);
  variable_kind get_kind (void) const;

protected:
  variable_kind m_kind;
};
} // namespace euclid

#endif