#include "lit_expression.hpp"
#include <iostream>

namespace euclid
{
using std::string, std::cout, std::get;
literal_expression::literal_expression (const literal_token &lit_token)
    : m_literal (lit_token.get_value ()),
      expression (expression_kind::LITERAL, lit_token.get_pos ())
{
  switch (lit_token.get_kind ())
    {
    case token_kind::STRING_LIT:
      m_kind = literal_kind::STRING;
      break;
    case token_kind::INT_LIT:
      m_kind = literal_kind::INTEGER;
      break;
    case token_kind::REAL_LIT:
      m_kind = literal_kind::REAL;
      break;
    case token_kind::BOOL_LIT:
      m_kind = literal_kind::BOOLEAN;
      break;
    }
}

void
literal_expression::print_variant () const
{
  switch (m_kind)
    {
    case literal_kind::STRING:
      cout << '\'' << get<string> (m_literal) << '\'';
      break;
    case literal_kind::INTEGER:
      cout << get<int> (m_literal);
      break;
    case literal_kind::REAL:
      cout << get<float> (m_literal);
      break;
    case literal_kind::BOOLEAN:
      cout << (get<bool> (m_literal) ? "true" : "false");
      break;
    }
  cout << '\n';
}

void
literal_expression::print (uint indent) const
{
  print_indent (indent);
  cout << "literal expression (\n";
  print_indent (indent + 1);
  print_variant ();
  print_indent (indent);
  cout << ")\n";
}
} // namespace euclid
