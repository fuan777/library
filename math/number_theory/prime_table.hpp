#pragma once
#include "../../template/type.hpp"

template <typename T = int>
vc<T> primetable(int LIM) {
  ++LIM;
  const int S = 32768;
  static int done = 2;
  static vc<T> primes = {2}, sieve(S + 1);
 
  if (done < LIM) {
    done = LIM;
 
    primes = {2}, sieve.assign(S + 1, 0);
    const int R = LIM / 2;
    primes.reserve(int(LIM / topbit(LIM) * 1.1));
    vc<std::pair<int, int>> cp;
    for (int i = 3; i <= S; i += 2) {
      if (!sieve[i]) {
        cp.eb(i, i * i / 2);
        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
      }
    }
    for (int L = 1; L <= R; L += S) {
      std::array<bool, S> block{};
      for (auto& [p, idx]: cp)
        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
      FOR(i, MIN(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);
    }
  }
  int k = LB(primes, LIM + 1);
  return {primes.begin(), primes.begin() + k};
}
 
// [0, LIM], 0, 1 填充 -1
vc<int> lpf_table(ll LIM) {
  auto primes = primetable(LIM);
  vc<int> res(LIM + 1, -1);
  FOR_R(i, len(primes)) {
    auto p = primes[i];
    FOR3(j, 1, LIM / p + 1) res[p * j] = p;
  }
  return res;
}