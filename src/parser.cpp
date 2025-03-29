#include "parser.hpp"
#include <array>
#include <iostream>
#include <span>

namespace euclid
{
using std::make_unique, std::move, std::unique_ptr, std::string, std::get,
    std::vector, std::unique_ptr, std::string_view, std::array;

void
parser::parse_file (string_view file_name)
{
  m_lexer.read_file (file_name);
  parse_program ();
}

void
parser::parse_string (const string &target_str)
{
  m_lexer = lexer (target_str);
  parse_program ();
}

void
parser::print_program () const
{
  m_program.print (0);
}

void
parser::not_implemented () const
{
  std::cerr << "Not implemented: " << token::look_up (m_current->get_kind ())
            << ".\n";
  std::exit (1);
}

unique_ptr<expression>
parser::parse_expression ()
{
  unique_ptr<expression> ret;
  return ret;
}

unique_ptr<assign_statement>
parser::parse_assign ()
{
  auto ret = make_unique<assign_statement> (
      move (static_cast<ident_token *> (m_current.get ())->get_name ()));
  return ret;
}

unique_ptr<compound_statement>
parser::parse_compound ()
{
  static array<token_kind, 1> expected_tokens = {
    token_kind::IDENT,
  };
  auto ret = make_unique<compound_statement> ();
  consume ();
  m_current->check_unexpected (expected_tokens);
  unique_ptr<statement> stmt;
  switch (m_current->get_kind ())
    {
    case token_kind::IDENT:
      consume ();
      m_current->check_unexpected (token_kind::ASGN);
      ret->append (parse_assign ());
      break;
    default:
      not_implemented ();
    }
  return ret;
}

unique_ptr<block>
parser::parse_block (bool is_main)
{
  auto ret = make_unique<block> ();
  static array<token_kind, 5> expected_tokens
      = { token_kind::BEGIN, token_kind::TYPE, token_kind::VAR,
          token_kind::CONST, token_kind::PROC };
  while ((m_current = m_lexer.get_next ())->get_kind () != token_kind::EOF)
    {
      m_current->check_invalid ();
      m_current->check_unexpected (expected_tokens);
      switch (m_current->get_kind ())
        {
        case token_kind::BEGIN:
          ret->set_stmt_part (parse_compound ());
          consume ();
          m_current->check_unexpected (token_kind::END);
          consume ();
          m_current->check_unexpected (is_main ? token_kind::DOT
                                               : token_kind::SEMIC);
          return ret;
        case token_kind::TYPE:
          not_implemented ();
          break;
        case token_kind::VAR:
          not_implemented ();
          break;
        case token_kind::CONST:
          not_implemented ();
          break;
        case token_kind::FUNCTION:
          not_implemented ();
          break;
        case token_kind::PROC:
          not_implemented ();
          break;
        }
    }
  std::cerr << "Error: Missing statements\n";
  std::exit (1);
}

void
parser::parse_program ()
{
  consume ();
  m_current->check_unexpected (token_kind::PROGRAM);
  consume ();
  m_current->check_unexpected (token_kind::IDENT);
  auto prog_name = static_cast<ident_token *> (m_current.get ())->get_name ();
  m_program.set_name (move (prog_name));
  consume ();
  m_current->check_unexpected (token_kind::SEMIC);
  m_program.set_block (parse_block (true));
}
} // namespace euclid
