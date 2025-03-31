#include "parser.hpp"
#include "deref_var.hpp"
#include "indexed_var.hpp"
#include "lit_expression.hpp"
#include "named_var.hpp"
#include "record_var.hpp"
#include <array>
#include <iostream>

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

unique_ptr<variable>
parser::parse_variable ()
{
  unique_ptr<variable> ret, ident;
  m_current->check_unexpected (token_kind::IDENT);
  ident = make_unique<named_var> (static_cast<ident_token &> (*m_current));
  consume ();
  switch (m_current->get_kind ())
    {
    case token_kind::DOT:
      consume ();
      ret = make_unique<record_var> (move (ident), parse_variable ());
      break;
    case token_kind::LBRACK:
      ret = make_unique<indexed_var> (move (ident), parse_expression ());
      consume ();
      m_current->check_unexpected (token_kind::RBRACK);
      break;
    case token_kind::PTR:
      ret = make_unique<deref_var> (move (ident));
    default:
      not_implemented ();
    }
  return ret;
}

unique_ptr<expression>
parser::parse_expression ()
{
  unique_ptr<expression> ret;
  consume ();
  switch (m_current->get_kind ())
    {
    case token_kind::INT_LIT:
    case token_kind::STRING_LIT:
    case token_kind::BOOL_LIT:
    case token_kind::REAL_LIT:
      m_l1 = m_lexer.get_next ();
      m_l1->check_unexpected (token_kind::SEMIC);
      ret = make_unique<literal_expression> (
          static_cast<literal_token &> (*m_current));
      break;
    default:
      not_implemented ();
    }

  return ret;
}

unique_ptr<assign_statement>
parser::parse_assign ()
{
  auto ret
      = make_unique<assign_statement> (parse_variable (), parse_expression ());
  return ret;
}

unique_ptr<compound_statement>
parser::parse_compound ()
{
  static array<token_kind, 2> expected_tokens = {
    token_kind::IDENT,
    token_kind::BEGIN,
  };
  auto ret = make_unique<compound_statement> ();
  consume ();
  while (m_current->get_kind () != token_kind::END)
    {
      m_current->check_unexpected (expected_tokens);

      switch (m_current->get_kind ())
        {
        case token_kind::IDENT:
          m_l1 = m_lexer.get_next ();
          m_l1->check_unexpected (token_kind::ASGN);
          ret->append (parse_assign ());
          break;
        case token_kind::BEGIN:
          ret->append (parse_compound ());
          consume ();
          m_current->check_unexpected (token_kind::SEMIC);
          break;
        default:
          not_implemented ();
        }
      consume ();
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
