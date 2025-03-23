#include "lit_expression.hpp"
#include <iostream>

namespace euclid
{
using std::string, std::cout, std::get_if, std::get;
literal_expression::literal_expression (
    const std::variant<int, float, bool, string> &literal, const position &pos)
    : m_literal (literal), expression (expression_kind::LITERAL, pos)
{
}

void
literal_expression::print_variant (void) const
{
  if (const int *ptr = get_if<int> (&m_literal))
    {
      cout << *ptr;
    }
  else if (const float *ptr = get_if<float> (&m_literal))
    {
      cout << *ptr;
    }
  else if (const bool *ptr = get_if<bool> (&m_literal))
    {
      cout << *ptr;
    }
  else
    {
      cout << get<string> (m_literal);
    }
  cout << '\n';
}

void
literal_expression::print (void) const
{
  cout << "literal expression (";
  print_variant ();
  cout << ")\n";
}
} // namespace euclid
