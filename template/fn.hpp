#pragma once

#include <algorithm>
#include <concepts>
#include <iterator>
#include <numeric>

#include "type.hpp"

// vector
#define COUNT(c, x) std::count(all(c), (x))
// LB(c, x) y < x in c
#define LB(c, x) std::distance((c).begin(), std::lower_bound(all(c), (x)))
// UB(c, x) y <= x in c
#define UB(c, x) std::distance((c).begin(), std::upper_bound(all(c), (x)))
#define UNIQUE(x) std::sort(all(x)), x.erase(std::unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T REV(T s) {
    std::reverse(all(s));
    return s;
}

template <typename T>
T POP(std::deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}

template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}

template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}

template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
};

template <typename T, typename U>
T SUM(const U &A) {
  return std::accumulate(A.begin(), A.end(), T{});
}

template <typename T>
T GCD(const vc<T> &A) {
  T g = 0;
  for (T x : A) g = gcd(g, x);
  return g;
}

// operation
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
std::pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}
 
template <typename Container>
requires requires(Container c) {
    { c.begin() } -> std::input_iterator;
    { c.end() } -> std::input_iterator;
}
auto MIN(const Container& c) {
    return *std::min_element(c.begin(), c.end());
}

template <typename T, typename... Ts>
T MIN(T a, Ts... args) {
    return std::min({a, args...});
}

template <typename Container>
requires requires(Container c) {
    { c.begin() } -> std::input_iterator;
    { c.end() } -> std::input_iterator;
}
auto MAX(const Container& c) {
    return *std::max_element(c.begin(), c.end());
}

template <typename T, typename... Ts>
T MAX(T a, Ts... args) {
    return std::max({a, args...});
}



// function
inline bool check_palindromic(const std::string &s) {
    return s == REV(s);
}

inline bool check_palindromic(ll x) {
    return check_palindromic(std::to_string(x));
}

std::string binary_transfer(ll x, ll base) {
    std::string res;
    while (x) {
        res += char(x % base + '0');
        x /= base;
    }
    return REV(res);
}

