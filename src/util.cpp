#include <cmath>
#include <array>

#include "util.hpp"

using std::size_t;


auto operator-(const std::array<size_t,3>& lhs, const std::array<size_t,3>& rhs) -> std::array<size_t, 3>    {
  std::array<size_t, 3> diff;
  for( size_t i = 0 ;  i!=3; ++i) {
    diff[i] = lhs[i] - rhs[i];
  }
  return diff;
}

auto operator*(const std::array<size_t,3>& lhs, double alpha) -> std::array<size_t, 3> {
std::array<size_t, 3> scaled_lhs;
  for( size_t i = 0 ;  i!=3; ++i) {
    scaled_lhs[i] = static_cast<size_t>(std::round(lhs[i] * alpha));
  }
  return scaled_lhs;
}
  

