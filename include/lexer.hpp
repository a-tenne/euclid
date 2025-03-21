#ifndef _LEXER_HPP
#define _LEXER_HPP
#include "token.hpp"
#include <map>
#include <memory>
#include <regex>

namespace euclid
{
class lexer
{
public:
  lexer (void);
  lexer (const std::string &target_str);
  std::unique_ptr<token> get_next (void);
  void read_file (const std::string &file_name);
  void print_remaining (void);

private:
  position m_pos;
  const char *m_current;
  std::string m_target_str;
  static const std::regex m_int_regex, m_real_regex;
  static const std::map<std::string, token_kind> m_keyword_lookup;
  static const std::unordered_map<char, token_kind> m_single_lookup;

  inline bool is_number_char (void);
  inline bool check_next (const char next, token_kind set_to,
                          std::unique_ptr<token> &tok);
  void advance (void);
  void skip_whitespace (void);
  void skip_comment (void);
  std::unique_ptr<token> non_alnum (void);
  std::unique_ptr<token> make_length_one (void);
  std::unique_ptr<token> make_invalid (const position &pos);
  std::unique_ptr<token> make_alnum (void);
  std::unique_ptr<token> make_number (void);
  std::unique_ptr<token> make_string (void);
};

} // namespace euclid

#endif