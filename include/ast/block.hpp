#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include "ast_node.hpp"
#include "compound_stmt.hpp"
#include <vector>

namespace euclid
{
class block : public ast_node
{
public:
  block () = default;
  void print (uint indent) const override;

private:
  compound_statement m_stmt_part;
};
} // namespace euclid

#endif