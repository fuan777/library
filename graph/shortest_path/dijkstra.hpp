#pragma once
#include "../base.hpp"
using namespace std;

template <typename T, typename GT>
pair<vc<T>, vc<int>> dijkstra_dense(GT& G, int s) {
  const int N = G.N;
  vc<T> dist(N, infty<T>);
  vc<int> par(N, -1);
  vc<bool> done(N);
  dist[s] = 0;
  while (1) {
    int v = -1;
    T mi = infty<T>;
    FOR(i, N) {
      if (!done[i] && chmin(mi, dist[i])) v = i;
    }
    if (v == -1) break;
    done[v] = 1;
    for (auto&& e: G[v]) {
      if (chmin(dist[e.to], dist[v] + e.cost)) par[e.to] = v;
    }
  }
  return {dist, par};
}

template <typename T, typename GT, bool DENSE = false>
pair<vc<T>, vc<int>> dijkstra(GT& G, int v) {
  if (DENSE) return dijkstra_dense<T>(G, v);
  auto N = G.N;
  vector<T> dist(N, infty<T>);
  vector<int> par(N, -1);
  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  dist[v] = 0;
  que.emplace(0, v);
  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        par[e.to] = e.frm;
        que.emplace(dist[e.to], e.to);
      }
    }
  }
  return {dist, par};
}

// 多点スタート。[dist, par, root]
template <typename T, typename GT>
tuple<vc<T>, vc<int>, vc<int>> dijkstra(GT& G, vc<int> vs) {
  assert(G.is_prepared());
  int N = G.N;
  vc<T> dist(N, infty<T>);
  vc<int> par(N, -1);
  vc<int> root(N, -1);

  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  for (auto&& v: vs) {
    dist[v] = 0;
    root[v] = v;
    que.emplace(T(0), v);
  }

  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        root[e.to] = root[e.frm];
        par[e.to] = e.frm;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  return {dist, par, root};
}