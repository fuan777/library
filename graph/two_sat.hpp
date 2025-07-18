#pragma once
#include "../template.hpp"
#include "base.hpp"
#include "connected_component.hpp"

#include <string>

struct TwoSat {
  Graph<bool, 1> G;
  vc<int> values;
  vc<std::pair<int, int>> edges;
 
  TwoSat(ll n) : G(n + n), values(n, -1) {}
  // a ∨ b : 至少true一个
  void add(int a, int b) {
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));
    edges.eb(a ^ 1, b);
    edges.eb(b ^ 1, a);
  }
  void set(int a) {
    if (a >= 0)
      values[a] = 1;
    else
      values[~a] = 0;
    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));
    edges.eb(a ^ 1, a);
  }
  // ¬a ∨ b :  a真 -> b真
  void implies(int a, int b) { add(~a, b); }
  void debug() {
    for (auto& [a, b]: edges) {
      std::string A, B;
      if (a % 2 == 0) A = "([" + std::to_string(a / 2) + "] == 0)";
      if (a % 2 == 1) A = "([" + std::to_string(a / 2) + "] == 1)";
      if (b % 2 == 0) B = "([" + std::to_string(b / 2) + "] == 0)";
      if (b % 2 == 1) B = "([" + std::to_string(b / 2) + "] == 1)";
      print(A, "->", B);
    }
  }
 
  std::pair<bool, vc<int>> calc() {
    UNIQUE(edges);
    for (auto&& [a, b]: edges) G.add(a, b);
    G.build();
    ll n = len(values);
    auto [C, comp] = strongly_connected_component(G);
    FOR(i, n) {
      if (comp[2 * i] == comp[2 * i + 1]) return {false, values};
      values[i] = comp[2 * i] < comp[2 * i + 1];
    }
    return {true, values};
  }
};