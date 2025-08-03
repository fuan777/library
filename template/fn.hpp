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
// change max/min
#define chmax(a, b) ((a) < (b) ? (a) = (b), 1 : 0)
#define chmin(a, b) ((a) > (b) ? (a) = (b), 1 : 0)

// ==================== 容器Function ====================
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
  for (T x : A) g = std::gcd(g, x);
  return g;
}

// 向下取整，向上取整，模运算，带余数除法
// C++默认是向0取整
template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return x / y + (x % y && (x ^ y) > 0);
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

// stl容器/多参数 MIN_MAX
template <std::ranges::range Container>
auto MIN(const Container& c) {
    return *std::ranges::min_element(c);
}
template <typename T, typename... Ts>
T MIN(T a, Ts... args) {
    return std::min({a, args...});
}
template <std::ranges::range Container>
auto MAX(const Container& c) {
    return *std::ranges::max_element(c);
}
template <typename T, typename... Ts>
T MAX(T a, Ts... args) {
    return std::max({a, args...});
}

// 回文串
inline bool check_palindromic(const std::string &s) {
    return s == REV(s);
}
inline bool check_palindromic(ll x) {
    return check_palindromic(std::to_string(x));
}

// 整型进制转换
template <typename T>
std::string binary_transfer(T x, T base) requires std::is_integral_v<T> {
    assert(base <= 16);
    std::string res;
    while (x) {
        res += (x % base < 10 ? char(x % base + '0') : char(x % base - 10 + 'A'));
        x /= base;
    }
    return REV(res);
}

// 通用 to_string（基础类型）
template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
inline std::string to_string(T x) {
    return std::to_string(x);
}
// 特化 to_string（__int128_t）
template <>
inline std::string to_string(__int128_t x) {
    if (x == 0) return "0";
    if (x < 0) return "-" + to_string(-x);
    std::string res;
    while (x) {
        res += char(x % 10 + '0');
        x /= 10;
    }
    return REV(res);
}