#ifndef UTIL_H
#define UTIL_H

using std::size_t;

auto operator-(const std::array<size_t,3>& lhs, const std::array<size_t,3>& rhs) -> std::array<size_t, 3>;


auto operator*(const std::array<size_t,3>& lhs, double alpha) -> std::array<size_t, 3>;

#endif 
