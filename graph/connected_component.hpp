#pragma once
#include "base.hpp"

template <typename GT>
std::pair<int, vc<int>> strongly_connected_component(GT& G) {
  static_assert(GT::is_directed);
  assert(G.is_prepared());
  int N = G.N;
  int C = 0;
  vc<int> comp(N), low(N), ord(N, -1), path;
  int now = 0;

  auto dfs = [&](auto& dfs, int v) -> void {
    low[v] = ord[v] = now++;
    path.eb(v);
    for (auto&& [frm, to, cost, id]: G[v]) {
      if (ord[to] == -1) {
        dfs(dfs, to), chmin(low[v], low[to]);
      } else {
        chmin(low[v], ord[to]);
      }
    }
    if (low[v] == ord[v]) {
      while (1) {
        int u = POP(path);
        ord[u] = N, comp[u] = C;
        if (u == v) break;
      }
      ++C;
    }
  };
  FOR(v, N) {
    if (ord[v] == -1) dfs(dfs, v);
  }
  FOR(v, N) comp[v] = C - 1 - comp[v];
  return {C, comp};
}

template <typename GT>
Graph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {
  Graph<int, 1> DAG(C);
  vvc<int> edges(C);
  for (auto&& e: G.edges) {
    int x = comp[e.frm], y = comp[e.to];
    if (x == y) continue;
    edges[x].eb(y);
  }
  FOR(c, C) {
    UNIQUE(edges[c]);
    for (auto&& to: edges[c]) DAG.add(c, to);
  }
  DAG.build();
  return DAG;
}


template <typename GT>
std::pair<int, vc<int>> two_edge_component(GT& G) {
  static_assert(!GT::is_directed);
  int N = G.N, M = G.M, n_comp = 0;
  vc<int> V, par(N, -2), dp(N), comp(N);
  V.reserve(N);
  vc<bool> used(M);
  auto dfs = [&](auto& dfs, int v) -> void {
    V.eb(v);
    for (auto&& e: G[v]) {
      if (used[e.id]) continue;
      if (par[e.to] != -2) dp[v]++, dp[e.to]--, used[e.id] = 1;
      if (par[e.to] == -2) {
        used[e.id] = 1;
        par[e.to] = v;
        dfs(dfs, e.to);
      }
    }
  };
  FOR(v, N) if (par[v] == -2) { par[v] = -1, dfs(dfs, v); }
  FOR_R(i, N) {
    if (par[V[i]] != -1) dp[par[V[i]]] += dp[V[i]];
  }
  for (auto&& v: V) comp[v] = (dp[v] == 0 ? n_comp++ : comp[par[v]]);
  return {n_comp, comp};
}