#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP
#include "ast_node.hpp"
#include "block.hpp"

namespace euclid
{
class program : public ast_node
{
public:
  void print (uint indent) const override;
  void set_name (std::string &&name);
  void set_block (std::unique_ptr<block> &&inner);

private:
  std::string m_name;
  std::unique_ptr<block> m_inner;
};
} // namespace euclid

#endif