#include "position.hpp"

namespace euclid
{

position::position (void) : m_col (1), m_row (1) {}

position::position (int row, int col) : m_col (col), m_row (row) {}

int
position::get_col () const
{
  return m_col;
}

int
position::get_row () const
{
  return m_row;
}

void
position::incr_col ()
{
  ++m_col;
}

void
position::incr_row ()
{
  m_col = 1;
  ++m_row;
}

} // namespace euclid
