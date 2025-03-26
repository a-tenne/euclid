#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP
#include "ast_node.hpp"
#include "block.hpp"

namespace euclid
{
class program : public ast_node
{
public:
  program () = default;
  void print (uint indent) const override;
  void set_name (std::string &&name);
  void set_block (block &&_block);

private:
  std::string m_name;
  block m_block;
};
} // namespace euclid

#endif