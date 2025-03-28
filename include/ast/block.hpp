#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include "ast_node.hpp"
#include "compound_stmt.hpp"
#include <memory>
#include <vector>

namespace euclid
{
class block : public ast_node
{
public:
  void print (uint indent) const override;
  void set_stmt_part (std::unique_ptr<compound_statement> &&stmt_part);

private:
  std::unique_ptr<compound_statement> m_stmt_part;
};
} // namespace euclid

#endif