#pragma once
#include "type.hpp"
#include "fn.hpp"

#include <unistd.h>
#include <iomanip>
#include <algorithm>

#define SYNC_OFF std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

namespace fastio {
// ===================== READ OPERATIONS =====================
template <typename T>
concept cin_able = requires(T x) { std::cin >> x; };
// cin支持
template <cin_able T>
void rd(T& x) {
    std::cin >> x;
}
// 特化 int128
void rd(__int128& x) {
    std::string s;
    std::cin >> s;
    x = 0;
    bool negative = (s[0] == '-');
    size_t start = (negative ? 1 : 0);
    for (size_t i = start; i < s.length(); ++i) {
        x = x * 10 + (s[i] - '0');
    }
    if (negative) x = -x;
}
template <typename T>
void rd(std::vector<T>& v) {
    for (auto& x : v) rd(x);
}
// array
template <typename T, size_t N>
void rd(std::array<T, N>& arr) {
    for (size_t i = 0; i < N; ++i) {
        rd(arr[i]);
    }
}
// pair
template <typename T1, typename T2>
void rd(std::pair<T1, T2>& p) {
    rd(p.fr);
    rd(p.se);
}
// tuple
template <typename... Args>
void rd(std::tuple<Args...>& t) {
    std::apply([&](auto&... args) { ((rd(args)), ...); }, t);
}
 
void read() {}
template <class H, class... T>
void read(H &h, T &... t) {
    rd(h), read(t...);
}

// ==================== WRITE OPERATIONS ====================
template <typename T>
concept cout_able = requires(T x) { std::cout << x; };
// cout支持
template <cout_able T>
void wt(const T& x) {
    std::cout << x;
}
// 特化
// int128
void wt(const __int128& x) {
    std::cout << to_string(x);
}

// vector
template <typename T>
void wt(const std::vector<T>& v) {
    wt("[");
    for (size_t i = 0; i < v.size(); ++i) {
        wt(v[i]); wt(i < v.size() - 1 ? " " : "");
    }
    wt("]");
}

// array
template <typename T, size_t N>
void wt(const std::array<T, N>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < N; ++i) {
        wt(arr[i]); wt(i < N - 1 ? " " : "");
    }
    std::cout << "]";
}

// pair
template <typename T1, typename T2>
void wt(const std::pair<T1, T2>& p) {
    wt("("); wt(p.fr); wt(","); wt(p.se); wt(")");
}

// tuple
template <typename... Args>
void wt(const std::tuple<Args...>& t) {
    wt("(");
    std::apply([&](const auto&... args) { ((wt(args), wt(" ")),...); }, t);
    wt(")");
}

// set
template <typename T>
void wt(const std::set<T>& s) {
    wt("{");
    for (auto it = s.begin(); it != s.end(); ++it) {
        wt(*it); wt(it != std::prev(s.end())? "," : "");
    }
    wt("}");
}
 
void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  wt(head);
  if (sizeof...(Tail)) wt(' ');
  print(std::forward<Tail>(tail)...);
}

inline void flush() {
    std::cout << std::flush;
}
 
// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
} // namespace fastio

using fastio::print;
 
// #if defined(LOCAL)
// #define SHOW(...) fastio::print(#__VA_ARGS__, __VA_ARGS__), flush()
// #else
// #define SHOW(...)
// #endif

#define INT(...)   \
  int __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define STR(...)      \
  std::string __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  fastio::read(__VA_ARGS__)
#define DOUBLE(...)      \
  double __VA_ARGS__; \
  fastio::read(__VA_ARGS__)

#define VEC(type, name, size) \
  std::vector<type> name(size);    \
  fastio::read(name)
#define VV(type, name, h, w)                     \
  std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
  fastio::read(name)