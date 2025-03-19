#ifndef _POSITION_HPP
#define _POSITION_HPP

namespace euclid
{
class position
{
public:
  position ();
  position (int row, int col);
  int get_col () const;
  int get_row () const;
  void incr_col ();
  void incr_row ();

private:
  int m_col, m_row;
};
} // namespace euclid

#endif