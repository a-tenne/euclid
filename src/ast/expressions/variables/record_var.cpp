#include "record_var.hpp"

namespace euclid
{
using std::string, std::unique_ptr, std::move;

record_var::record_var (const string &field, unique_ptr<variable> var,
                        const position &pos)
    : m_field (field), m_var (move (var)),
      variable (variable_kind::REC_FIELD, pos)
{
}
} // namespace euclid
