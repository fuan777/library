#pragma once
#include "../../template/type.hpp"
#include "../../template/bits.hpp"
#include "../random/base.hpp"
#include "prime_test.hpp"


template <typename mint>
ll rho(ll n, ll c) {
  assert(n > 1);
  const mint cc(c);
  auto f = [&](mint x) { return x * x + cc; };
  mint x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (topbit(n) / 5);
  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(r) y = f(y);
    for (ll k = 0; k < r && g == 1; k += m) {
      z = y;
      FOR(std::min(m, r - k)) y = f(y), q *= x - y;
      g = std::gcd(q.val(), n);
    }
  }
  if (g == n) do {
      z = f(z);
      g = std::gcd((x - z).val(), n);
    } while (g == 1);
  return g;
}

ll find_prime_factor(ll n) {
  assert(n > 1);
  if (primetest(n)) return n;
  FOR(100) {
    ll m = 0;
    if (n < (1 << 30)) {
      using mint = Mongomery_modint_32<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    } else {
      using mint = Mongomery_modint_64<20231025>;
      mint::set_mod(n);
      m = rho<mint>(n, RNG(0, n));
    }
    if (primetest(m)) return m;
    n = m;
  }
  assert(0);
  return -1;
}

vc<std::pair<ll, int>> factor(ll n) {
  assert(n >= 1);
  vc<std::pair<ll, int>> pf;
  FOR(p, 2, 100) {
    if (p * p > n) break;
    if (n % p == 0) {
      ll e = 0;
      do { n /= p, e += 1; } while (n % p == 0);
      pf.eb(p, e);
    }
  }
  while (n > 1) {
    ll p = find_prime_factor(n);
    ll e = 0;
    do { n /= p, e += 1; } while (n % p == 0);
    pf.eb(p, e);
  }
  sort(all(pf));
  return pf;
}

vc<std::pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {
  vc<std::pair<ll, int>> res;
  while (n > 1) {
    int p = lpf[n];
    int e = 0;
    while (n % p == 0) {
      n /= p;
      ++e;
    }
    res.eb(p, e);
  }
  return res;
}