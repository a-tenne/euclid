#ifndef _NODE_HPP
#define _NODE_HPP
#include <iostream>
#include <sys/types.h>
namespace euclid
{

class ast_node
{
public:
  virtual void print (uint indent) const = 0;
  static inline void
  print_indent (uint indent)
  {
    for (uint i = 0; i < indent; ++i)
      std::cout << "  ";
  }
};

} // namespace euclid

#endif