#ifndef _LEXER_HPP
#define _LEXER_HPP
#include "token.hpp"
#include <map>
#include <memory>

namespace euclid
{
class lexer
{
public:
  lexer ();
  lexer (const std::string &target_str);
  std::unique_ptr<token> get_next (void);
  void read_file (const std::string &file_name);

private:
  position m_pos;
  const char *m_current;
  std::string m_target_str;

  std::unique_ptr<token> make_prim (token_kind kind, const position &pos);
  std::unique_ptr<bool_token> make_bool (const position &pos, bool value);
  std::unique_ptr<int_token> make_int (const position &pos, int value);
  std::unique_ptr<real_token> make_real (const position &pos, float value);
  std::unique_ptr<string_token> make_string (const position &pos,
                                             const std::string &value);
  std::unique_ptr<ident_token> make_ident (const position &pos,
                                           const std::string &name);

  static const std::map<std::string, token_kind> m_keyword_lookup;
  static const std::unordered_map<char, token_kind> m_char_lookup;
};

} // namespace euclid

#endif