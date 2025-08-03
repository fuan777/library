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

#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fr first
#define se second
 
#define stoi stoll