#ifndef _NODE_HPP
#define _NODE_HPP

namespace euclid
{

class ast_node
{
public:
  virtual void print (void) = 0;
};

} // namespace euclid

#endif