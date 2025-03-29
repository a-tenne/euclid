#ifndef _PARSER_HPP
#define _PARSER_HPP
#include "assign_stmt.hpp"
#include "expression.hpp"
#include "lexer.hpp"
#include "program.hpp"
#include <memory>

namespace euclid
{
class parser
{
public:
  parser () = default;
  void parse_string (const std::string &target_str);
  void parse_file (std::string_view file_name);
  void print_program () const;
  void not_implemented () const;

private:
  lexer m_lexer;
  program m_program;
  std::unique_ptr<token> m_current;

  void parse_program ();
  std::unique_ptr<block> parse_block (bool is_main);
  std::unique_ptr<compound_statement> parse_compound ();
  std::unique_ptr<assign_statement> parse_assign ();
  std::unique_ptr<expression> parse_expression ();
  void
  consume ()
  {
    m_current = m_lexer.get_next ();
  }
};
} // namespace euclid

#endif