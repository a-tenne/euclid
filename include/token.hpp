#ifndef _TOKEN_HPP
#define _TOKEN_HPP
#include "position.hpp"
#include <string>
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

class prim_token
{
public:
  prim_token (position pos);
  prim_token (token_kind kind, position pos);
  token_kind get_kind (void) const;
  const position &get_pos (void) const;
  virtual std::string to_string (void) const;

protected:
  token_kind m_kind;
  position m_pos;
};

class bool_token : public prim_token
{
public:
  bool_token (position pos, bool value);
  bool get_value () const;
  std::string to_string (void) const override;

private:
  bool m_value;
};

class int_token : public prim_token
{
public:
  int_token (position pos, int value);
  int get_value () const;
  std::string to_string (void) const override;

private:
  int m_value;
};

class real_token : public prim_token
{
public:
  real_token (position pos, float value);
  float get_value () const;
  std::string to_string (void) const override;

private:
  float m_value;
};

class string_token : public prim_token
{
public:
  string_token (position pos, std::string value);
  const std::string &get_value () const;
  std::string to_string (void) const override;

private:
  std::string m_value;
};

class ident_token : public prim_token
{
public:
  ident_token (position pos, std::string name);
  const std::string &get_name () const;
  std::string to_string (void) const override;

private:
  std::string m_name;
};

} // namespace euclid

#endif