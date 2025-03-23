#include "token.hpp"
#define LOOKUP_ENTRY(TOKEN) { token_kind::TOKEN, #TOKEN }
namespace euclid
{

using std::string, std::variant, std::get, std::get_if;

const std::unordered_map<token_kind, string> token::str_lookup = {
  LOOKUP_ENTRY (INVALID),  LOOKUP_ENTRY (AND),        LOOKUP_ENTRY (ARRAY),
  LOOKUP_ENTRY (BEGIN),    LOOKUP_ENTRY (CASE),       LOOKUP_ENTRY (CONST),
  LOOKUP_ENTRY (DIV),      LOOKUP_ENTRY (DO),         LOOKUP_ENTRY (DOWNTO),
  LOOKUP_ENTRY (ELSE),     LOOKUP_ENTRY (END),        LOOKUP_ENTRY (FILE),
  LOOKUP_ENTRY (FOR),      LOOKUP_ENTRY (FUNCTION),   LOOKUP_ENTRY (GOTO),
  LOOKUP_ENTRY (IF),       LOOKUP_ENTRY (IN),         LOOKUP_ENTRY (LABEL),
  LOOKUP_ENTRY (MOD),      LOOKUP_ENTRY (NIL),        LOOKUP_ENTRY (NOT),
  LOOKUP_ENTRY (OF),       LOOKUP_ENTRY (OR),         LOOKUP_ENTRY (PACKED),
  LOOKUP_ENTRY (PROC),     LOOKUP_ENTRY (PROGRAM),    LOOKUP_ENTRY (RECORD),
  LOOKUP_ENTRY (REPEAT),   LOOKUP_ENTRY (SET),        LOOKUP_ENTRY (THEN),
  LOOKUP_ENTRY (TO),       LOOKUP_ENTRY (TYPE),       LOOKUP_ENTRY (UNTIL),
  LOOKUP_ENTRY (VAR),      LOOKUP_ENTRY (WHILE),      LOOKUP_ENTRY (WITH),
  LOOKUP_ENTRY (PLUS),     LOOKUP_ENTRY (MINUS),      LOOKUP_ENTRY (ASTERISK),
  LOOKUP_ENTRY (SLASH),    LOOKUP_ENTRY (EQ),         LOOKUP_ENTRY (LT),
  LOOKUP_ENTRY (GT),       LOOKUP_ENTRY (LBRACK),     LOOKUP_ENTRY (RBRACK),
  LOOKUP_ENTRY (DOT),      LOOKUP_ENTRY (COMMA),      LOOKUP_ENTRY (COLON),
  LOOKUP_ENTRY (SEMIC),    LOOKUP_ENTRY (PTR),        LOOKUP_ENTRY (LPAREN),
  LOOKUP_ENTRY (RPAREN),   LOOKUP_ENTRY (NE),         LOOKUP_ENTRY (LE),
  LOOKUP_ENTRY (GE),       LOOKUP_ENTRY (ASGN),       LOOKUP_ENTRY (RANGE),
  LOOKUP_ENTRY (TRUE),     LOOKUP_ENTRY (BOOL_LIT),   LOOKUP_ENTRY (INT_LIT),
  LOOKUP_ENTRY (REAL_LIT), LOOKUP_ENTRY (STRING_LIT), LOOKUP_ENTRY (IDENT),
  LOOKUP_ENTRY (EOF)
};

token::token (position pos) : m_kind (token_kind::INVALID), m_pos (pos) {}

token::token (token_kind kind, const position &pos)
    : m_kind (kind), m_pos (pos)
{
}

token_kind
token::get_kind (void) const
{
  return m_kind;
}
const position &
token::get_pos (void) const
{
  return m_pos;
}

string
token::to_string (void) const
{
  return str_lookup.at (m_kind);
}

/* bool_token::bool_token (position pos, bool value)
    : token (token_kind::BOOL_LIT, pos), m_value (value)
{
}

bool
bool_token::get_value (void) const
{
  return m_value;
}

string
bool_token::to_string (void) const
{
  return token::to_string () + ": " + (m_value ? "TRUE" : "FALSE");
}

int_token::int_token (position pos, int value)
    : token (token_kind::INT_LIT, pos), m_value (value)
{
}

int
int_token::get_value (void) const
{
  return m_value;
}

string
int_token::to_string (void) const
{
  return token::to_string () + ": " + std::to_string (m_value);
}

real_token::real_token (position pos, float value)
    : token (token_kind::REAL_LIT, pos), m_value (value)
{
}

float
real_token::get_value (void) const
{
  return m_value;
}

string
real_token::to_string (void) const
{
  return token::to_string () + ": " + std::to_string (m_value);
}

string_token::string_token (position pos, const string &value)
    : token (token_kind::STRING_LIT, pos), m_value (value)
{
}

const string &
string_token::get_value (void) const
{
  return m_value;
}

string
string_token::to_string (void) const
{
  return token::to_string () + ": '" + m_value + "'";
} */

ident_token::ident_token (position pos, const string &name)
    : token (token_kind::IDENT, pos), m_name (name)
{
}

const string &
ident_token::get_name (void) const
{
  return m_name;
}

string
ident_token::to_string (void) const
{
  return token::to_string () + ": " + m_name;
}

literal_token::literal_token (token_kind kind,
                              variant<int, float, bool, string> value,
                              const position &pos)
    : m_value (value), token (kind, pos)
{
}

string
literal_token::to_string (void) const
{
  string str = token::to_string () + ": ";
  if (const int *ptr = get_if<int> (&m_value))
    {
      str += std::to_string (*ptr);
    }
  else if (const float *ptr = get_if<float> (&m_value))
    {
      str += std::to_string (*ptr);
    }
  else if (const bool *ptr = get_if<bool> (&m_value))
    {
      str += *ptr ? "true" : "false";
    }
  else
    {
      str += '\'' + get<string> (m_value) + '\'';
    }
  return str;
}
const std::variant<int, float, bool, std::string> &
literal_token::get_value (void) const
{
  return m_value;
}

} // namespace euclid
