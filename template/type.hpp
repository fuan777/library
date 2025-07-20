#pragma once

#include <iostream>

using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;

#include <cstring>
#include <cstdint>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <assert.h>

#include <set>
#include <map>

using pi = std::pair<ll, ll>;
using vi = std::vector<ll>;
template <class T>
using vc = std::vector<T>;
template <class T>
using vvc = std::vector<vc<T>>;
template <class T>
using vvvc = std::vector<vvc<T>>;
template <class T>
using vvvvc = std::vector<vvvc<T>>;
template <class T>
using vvvvvc = std::vector<vvvvc<T>>;
template <class T>
using pq = std::priority_queue<T>;
template <class T>
using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define vv(type, name, h, ...) std::vector<std::vector<type>> name(h, std::vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) std::vector<std::vector<std::vector<type>>> name(h, std::vector<std::vector<type>>(w, std::vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...) \
    std::vector<std::vector<std::vector<std::vector<type>>>> name(a, std::vector<std::vector<std::vector<type>>>(b, std::vector<std::vector<type>>(c, std::vector<type>(__VA_ARGS__))))


#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
 
#define stoi stoll