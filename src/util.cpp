#include <cmath>
#include <array>

#include "util.hpp"

auto operator-(const std::array<double,3>& lhs, const std::array<double,3>& rhs) -> std::array<double, 3>    {
  std::array<double, 3> diff;
  for( double i = 0 ;  i!=3; ++i) {
    diff[i] = lhs[i] - rhs[i];
  }
  return diff;
}

auto operator+(const std::array<double,3>& lhs, const std::array<double,3>& rhs) -> std::array<double, 3> {
  std::array<double, 3> diff;
  for( double i = 0 ;  i!=3; ++i) {
    diff[i] = lhs[i] +  rhs[i];
  }
  return diff;
}


auto operator*(const std::array<double,3>& lhs, double alpha) -> std::array<double, 3> {
std::array<double, 3> scaled_lhs;
  for( double i = 0 ;  i!=3; ++i) {
    scaled_lhs[i] = static_cast<double>(std::round(lhs[i] * alpha));
  }
  return scaled_lhs;
}
  

