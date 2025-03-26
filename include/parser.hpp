#ifndef _PARSER_HPP
#define _PARSER_HPP
#include "lexer.hpp"
#include "program.hpp"
#include <memory>

namespace euclid
{
class parser
{
public:
  parser ();
  void parse_file (const std::string &file_name);
  void print_program (void) const;
  void not_implemented (void) const;

private:
  lexer m_lexer;
  program m_program;
  std::unique_ptr<token> m_current;

  void parse_program (void);
};
} // namespace euclid

#endif