#include "lexer.hpp"
#include <fstream>
#include <iostream>

#define U_TOKEN(_token, position)                                             \
  (make_unique<token> (token_kind::_token, position))

namespace euclid
{
using std::string, std::unique_ptr, std::make_unique, std::unordered_map,
    std::regex, std::map;

const regex lexer::m_int_regex = regex (R"(^\d+$)");
const regex lexer::m_real_regex = regex (R"(^\d+\.\d+(e[\+-]?\d+)?$)");
const map<string, token_kind> lexer::m_keyword_lookup
    = { { "and", token_kind::AND },
        { "array", token_kind::ARRAY },
        { "begin", token_kind::BEGIN },
        { "case", token_kind::CASE },
        { "const", token_kind::CONST },
        { "div", token_kind::DIV },
        { "do", token_kind::DO },
        { "downto", token_kind::DOWNTO },
        { "else", token_kind::ELSE },
        { "end", token_kind::END },
        { "file", token_kind::FILE },
        { "for", token_kind::FOR },
        { "function", token_kind::FUNCTION },
        { "goto", token_kind::GOTO },
        { "if", token_kind::IF },
        { "in", token_kind::IN },
        { "label", token_kind::LABEL },
        { "mod", token_kind::MOD },
        { "nil", token_kind::NIL },
        { "not", token_kind::NOT },
        { "of", token_kind::OF },
        { "or", token_kind::OR },
        { "packed", token_kind::PACKED },
        { "procedure", token_kind::PROC },
        { "program", token_kind::PROGRAM },
        { "record", token_kind::RECORD },
        { "repeat", token_kind::REPEAT },
        { "set", token_kind::SET },
        { "then", token_kind::THEN },
        { "to", token_kind::TO },
        { "type", token_kind::TYPE },
        { "until", token_kind::UNTIL },
        { "var", token_kind::VAR },
        { "while", token_kind::WHILE },
        { "with", token_kind::WITH } };
const unordered_map<char, token_kind> lexer::m_single_lookup
    = { { '+', token_kind::PLUS },     { '-', token_kind::MINUS },
        { '*', token_kind::ASTERISK }, { '/', token_kind::SLASH },
        { '=', token_kind::EQ },       { '[', token_kind::LBRACK },
        { ']', token_kind::RBRACK },   { ',', token_kind::COMMA },
        { ';', token_kind::SEMIC },    { '^', token_kind::PTR },
        { ')', token_kind::RPAREN } };

lexer::lexer (void) : m_pos (), m_target_str (), m_current (nullptr) {}
lexer::lexer (const string &target_str)
    : m_pos (), m_target_str (target_str), m_current (m_target_str.c_str ())
{
}

void
lexer::read_file (const string &file_name)
{
  std::ifstream file (file_name, std::ios::in);
  size_t len = file.seekg (0, std::ios::end).tellg ();
  m_target_str = string (len, '\0');
  file.seekg (std::ios::beg)
      .read (const_cast<char *> (m_target_str.c_str ()), len);
  for (auto &c : m_target_str)
    c = std::tolower (static_cast<u_char> (c));
  m_current = m_target_str.c_str ();
}

void
lexer::advance (void)
{
  ++m_current;
  m_pos.incr_col ();
}

void
lexer::skip_whitespace (void)
{
  while (std::isspace (static_cast<u_char> (*m_current)))
    {
      switch (*m_current)
        {
        case '\t':
          for (u_char i = 0; i < 4; ++i)
            m_pos.incr_col ();
          break;
        case '\n':
          m_pos.incr_row ();
          break;
        default:
          m_pos.incr_col ();
        }
      ++m_current;
    }
}

void
lexer::skip_comment (void)
{
  if (*m_current == '{')
    {
      while (*m_current != '\0')
        {
          if (*m_current == '}')
            {
              advance ();
              break;
            }
          if (std::isspace (static_cast<u_char> (*m_current)))
            {
              skip_whitespace ();
            }
          else
            advance ();
        }
    }
  else
    {
      while (*m_current != '\0')
        {
          if (*m_current == '*' && m_current[1] == ')')
            {
              advance ();
              advance ();
              break;
            }
          if (std::isspace (static_cast<u_char> (*m_current)))
            {
              skip_whitespace ();
            }
          else
            advance ();
        }
    }
}

// TODO: implement this
unique_ptr<token>
lexer::get_next (void)
{
  skip_whitespace ();

  if (m_current == nullptr)
    return make_invalid (m_pos);

  if (*m_current == '\0')
    return make_unique<token> (token_kind::EOF, m_pos);

  if (std::isalpha (static_cast<u_char> (*m_current)))
    return make_alnum ();

  if (*m_current == '\'')
    {
      advance ();
      return make_string ();
    }

  if (std::isdigit (static_cast<u_char> (*m_current)))
    return make_number ();

  return non_alnum ();
}

inline bool
lexer::check_next (const char next, token_kind set_to, unique_ptr<token> &tok)
{
  if (m_current[1] == next)
    {
      tok = make_unique<token> (set_to, m_pos);
      advance ();
      return true;
    }
  return false;
}

unique_ptr<token>
lexer::non_alnum (void)
{
  unique_ptr<token> tok;
  switch (*m_current)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '[':
    case ']':
    case ',':
    case ';':
    case '^':
    case ')':
      tok = make_length_one ();
      break;
    case ':':
      if (check_next ('=', token_kind::ASGN, tok))
        break;
      tok = U_TOKEN (COLON, m_pos);
      break;
    case '<':
      if (check_next ('>', token_kind::NE, tok))
        break;
      if (check_next ('=', token_kind::LE, tok))
        break;
      tok = U_TOKEN (LT, m_pos);
      break;
    case '>':
      if (check_next ('=', token_kind::GE, tok))
        break;
      tok = U_TOKEN (GT, m_pos);
      break;
    case '.':
      if (check_next ('.', token_kind::RANGE, tok))
        break;
      tok = U_TOKEN (DOT, m_pos);
      break;
    case '{':
      skip_comment ();
      return get_next ();
    case '(':
      if (m_current[1] == '*')
        {
          advance ();
          advance ();
          skip_comment ();
          return get_next ();
        }
      tok = U_TOKEN (LPAREN, m_pos);
      break;
    default:
      return make_invalid (m_pos);
    }
  advance ();
  return tok;
}

unique_ptr<token>
lexer::make_length_one (void)
{
  return make_unique<token> (m_single_lookup.at (*m_current), m_pos);
}

unique_ptr<token>
lexer::make_alnum (void)
{
  string str;
  position start = m_pos;
  while (std::isalnum (static_cast<u_char> (*m_current)))
    {
      str += *m_current;
      advance ();
    }
  auto it = m_keyword_lookup.find (str);
  if (it != m_keyword_lookup.end ())
    return make_unique<token> (it->second, start);
  if (str == "false" || str == "true")
    return make_unique<bool_token> (start, str == "true");
  return make_unique<ident_token> (start, str);
}

inline bool
lexer::is_number_char (void)
{
  return std::isdigit (static_cast<u_char> (*m_current)) || *m_current == 'e'
         || *m_current == '-' || *m_current == '+' || *m_current == '.';
}

unique_ptr<token>
lexer::make_number (void)
{
  string num_str;
  position start = m_pos;
  while (is_number_char ())
    {
      if (*m_current == '.' && m_current[1] == '.')
        break;
      num_str += *m_current;
      advance ();
    }
  if (regex_match (num_str, m_real_regex))
    return make_unique<real_token> (start, std::stof (num_str));
  if (regex_match (num_str, m_int_regex))
    return make_unique<int_token> (start, std::stoi (num_str));

  return make_invalid (start);
}

unique_ptr<token>
lexer::make_invalid (const position &pos)
{
  return make_unique<token> (token_kind::INVALID, pos);
}

unique_ptr<token>
lexer::make_string (void)
{
  string str;
  position start = m_pos;
  while (*m_current != '\0' && *m_current != '\'' && *m_current != '\n')
    {
      str += *m_current;
      advance ();
    }
  if (*m_current == '\'')
    {
      advance ();
      return make_unique<string_token> (start, str);
    }
  return make_invalid (start);
}

void
lexer::print_remaining (void)
{
  unique_ptr<token> current = get_next ();
  std::cout << "[ ";
  while (current->get_kind () != token_kind::EOF)
    {
      if (current->get_kind () == token_kind::INVALID)
        {
          position pos = current->get_pos ();
          std::cout << "Invalid token on line " << pos.get_row () << " column "
                    << pos.get_col () << ".\n";
          return;
        }
      std::cout << current->to_string () << ", ";
      current = get_next ();
    }
  std::cout << current->to_string () << " ]\n";
}

} // namespace euclid
