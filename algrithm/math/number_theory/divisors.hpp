#pragma once
#include "../../template/type.hpp"
#include "../../template/bits.hpp"
#include "factor.hpp"

vc<ll> divisors_by_pf(const vc<std::pair<ll, int>>& pf) {
  vc<ll> div = {1};
  for (auto&& [p, e]: pf) {
    ll n = len(div);
    ll pp = 1;
    FOR3(i, 1, e + 1) {
      pp *= p;
      FOR(j, n) div.eb(div[j] * pp);
    }
  }
  return div;
}

vc<ll> divisors(ll N) {
  auto pf = factor(N);
  return divisors_by_pf(pf);
}

vc<ll> divisors_by_lpf(ll N, vc<int>& lpf) {
  auto pf = factor_by_lpf(N, lpf);
  return divisors_by_pf(pf);
}