#pragma once

#include "../../template.hpp"

template <typename E>
struct Monoid_Min {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return std::min(x, y); }
  static constexpr X unit() { return infty<E>; }
  static constexpr bool commute = true;
};