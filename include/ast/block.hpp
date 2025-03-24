#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include "ast_node.hpp"

namespace euclid
{
class block : public ast_node
{
public:
  void print (uint indent) const override;

private:
};
} // namespace euclid

#endif