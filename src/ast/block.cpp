#include "block.hpp"

namespace euclid
{
using std::cout, std::move, std::unique_ptr;
void
block::set_stmt_part (unique_ptr<compound_statement> &&stmt_part)
{
  m_stmt_part = move (stmt_part);
}

void
block::print (uint indent) const
{
  print_indent (indent);
  cout << "block (\n";
  m_stmt_part->print (indent + 1);
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
