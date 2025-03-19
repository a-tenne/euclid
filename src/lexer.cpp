#include "lexer.hpp"
#include <fstream>
namespace euclid
{
using std::string, std::unique_ptr, std::make_unique, std::unordered_map,
    std::map;
lexer::lexer () : m_pos (), m_target_str (), m_current (nullptr) {}
lexer::lexer (const string &target_str)
    : m_pos (), m_target_str (target_str), m_current (m_target_str.c_str ())
{
}

void
lexer::read_file (const string &file_name)
{
  std::ifstream file (file_name);
  size_t len = file.seekg (std::ios::end).tellg ();
  m_target_str = string (len, '\0');
  file.seekg (std::ios::beg)
      .read (const_cast<char *> (m_target_str.c_str ()), len);
  m_current = m_target_str.c_str ();
}

unique_ptr<token>
lexer::get_next (void)
{
  if (m_current == nullptr)
    return make_prim (token_kind::INVALID, m_pos);
  return make_prim (token_kind::INVALID, m_pos);
}

unique_ptr<token>
lexer::make_prim (token_kind kind, const position &pos)
{
  return make_unique<token> (kind, pos);
}

unique_ptr<bool_token>
lexer::make_bool (const position &pos, bool value)
{
  return make_unique<bool_token> (pos, value);
}

unique_ptr<int_token>
lexer::make_int (const position &pos, int value)
{
  return make_unique<int_token> (pos, value);
}

unique_ptr<real_token>
lexer::make_real (const position &pos, float value)
{
  return make_unique<real_token> (pos, value);
}

unique_ptr<string_token>
lexer::make_string (const position &pos, const string &value)
{
  return make_unique<string_token> (pos, value);
}

unique_ptr<ident_token>
lexer::make_ident (const position &pos, const string &name)
{
  return make_unique<ident_token> (pos, name);
}

} // namespace euclid
