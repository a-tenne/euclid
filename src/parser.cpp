#include "parser.hpp"
#include <iostream>

namespace euclid
{
using std::move, std::unique_ptr, std::string, std::get;
parser::parser () : m_lexer (), m_current (nullptr) {}

void
parser::parse_file (const std::string &file_name)
{
  m_lexer.read_file (file_name);
  parse_program ();
}

void
parser::print_program (void) const
{
  m_program.print (0);
}

void
parser::not_implemented (void) const
{
  std::cerr << "Not implemented: " << token::look_up (m_current->get_kind ())
            << "\n";
  std::exit (1);
}

void
parser::parse_program (void)
{

  m_current = m_lexer.get_next ();
  m_current->check_unexpected (token_kind::PROGRAM);
  m_current = m_lexer.get_next ();
  m_current->check_unexpected (token_kind::IDENT);
  auto prog_name = static_cast<ident_token *> (m_current.get ())->get_name ();
  m_program.set_name (move (prog_name));
  m_current = m_lexer.get_next ();
  m_current->check_unexpected (token_kind::SEMIC);
  while ((m_current = m_lexer.get_next ())->get_kind () != token_kind::EOF)
    {
      m_current->check_invalid ();
      token_kind kind = m_current->get_kind ();
      switch (kind)
        {
        case token_kind::BEGIN:
          m_current = m_lexer.get_next ();
          kind = m_current->get_kind ();
          m_current->check_unexpected (token_kind::END);
          m_current = m_lexer.get_next ();
          kind = m_current->get_kind ();
          m_current->check_unexpected (token_kind::DOT);
          return;
          break;
        default:
          not_implemented ();
          break;
        }
    }
}
} // namespace euclid
