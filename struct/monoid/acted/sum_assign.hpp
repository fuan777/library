#include "../../monoid/base/add.hpp"
#include "../../monoid/base/assign.hpp"

template <typename E, E none_val = E{}>
struct ActedMonoid_Sum_Assign {
  using Monoid_X = Monoid_Add<E>;
  using Monoid_A = Monoid_Assign<E, none_val>;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;
  static constexpr X act(const X &x, const A &a, const ll &size) {
    if (a == Monoid_A::unit()) return x;
    return a * E(size);
  }
};