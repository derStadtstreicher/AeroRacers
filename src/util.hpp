#ifndef UTIL_H
#define UTIL_H

auto operator-(const std::array<double,3>& lhs, const std::array<double,3>& rhs) -> std::array<double, 3>;

auto operator+(const std::array<double,3>& lhs, const std::array<double,3>& rhs) -> std::array<double, 3>;

auto operator*(const std::array<double,3>& lhs, double alpha) -> std::array<double, 3>;

#endif 
