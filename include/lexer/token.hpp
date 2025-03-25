#ifndef _TOKEN_HPP
#define _TOKEN_HPP
#include "position.hpp"
#include <string>
#include <unordered_map>
#include <variant>
#undef EOF
namespace euclid
{

enum class token_kind
{
  INVALID,
  AND,
  ARRAY,
  BEGIN,
  CASE,
  CONST,
  DIV,
  DO,
  DOWNTO,
  ELSE,
  END,
  FILE,
  FOR,
  FUNCTION,
  GOTO,
  IF,
  IN,
  LABEL,
  MOD,
  NIL,
  NOT,
  OF,
  OR,
  PACKED,
  PROC,
  PROGRAM,
  RECORD,
  REPEAT,
  SET,
  THEN,
  TO,
  TYPE,
  UNTIL,
  VAR,
  WHILE,
  WITH,
  PLUS,
  MINUS,
  ASTERISK,
  SLASH,
  EQ,
  LT,
  GT,
  LBRACK,
  RBRACK,
  DOT,
  COMMA,
  COLON,
  SEMIC,
  PTR,
  LPAREN,
  RPAREN,
  NE,
  LE,
  GE,
  ASGN,
  RANGE,
  TRUE,
  BOOL_LIT,
  INT_LIT,
  REAL_LIT,
  STRING_LIT,
  IDENT,
  EOF,
};

class token
{
public:
  token () = delete;
  token (token_kind kind, const position &pos);
  token_kind get_kind (void) const;
  const position &get_pos (void) const;
  void check_invalid (void) const;
  void check_unexpected (token_kind kind) const;
  virtual std::string to_string (void) const;
  inline static const std::string &
  look_up (token_kind kind)
  {
    return str_lookup.at (kind);
  }

protected:
  token (position pos);
  token_kind m_kind;
  position m_pos;
  static const std::unordered_map<token_kind, std::string> str_lookup;
};

class literal_token : public token
{
public:
  literal_token () = delete;
  literal_token (token_kind kind,
                 std::variant<int, float, bool, std::string> value,
                 const position &pos);
  const std::variant<int, float, bool, std::string> &get_value (void) const;
  std::string to_string (void) const override;

private:
  std::variant<int, float, bool, std::string> m_value;
};

class ident_token : public token
{
public:
  ident_token (position pos, const std::string &name);
  const std::string &get_name (void) const;
  std::string to_string (void) const override;

private:
  std::string m_name;
};

} // namespace euclid

#endif