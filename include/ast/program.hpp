#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP
#include "ast_node.hpp"
#include "block.hpp"

namespace euclid
{
class program : public ast_node
{
public:
  program (const std::string &name, const block &_block);
  void print (uint indent) const override;

private:
  std::string m_name;
  block m_block;
};
} // namespace euclid

#endif