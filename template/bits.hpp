#pragma once
#include "type.hpp"

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T kth_bit(int k) {
    return T(1) << k;
}
template <typename T>
bool has_kth_bit(T x, int k) {
    return x >> k & 1;
}

template <typename UINT>
struct all_bit {
    struct iter {
        UINT s;
        iter(UINT s) : s(s) {}
        int operator*() const { return lowbit(s); }
        iter &operator++() {
            s &= s - 1;
            return *this;
        }
        bool operator!=(const iter) const { return s != 0; }
    };
    UINT s;
    all_bit(UINT s) : s(s) {}
    iter begin() const { return iter(s); }
    iter end() const { return iter(0); }
};

template <typename UINT>
struct all_subset {
    struct iter {
        UINT s, t;
        bool ed;
        iter(UINT s) : s(s), t(s), ed(0) {}
        int operator*() const { return s ^ t; }
        iter &operator++() {
            (t == 0 ? ed = 1 : t = (t - 1) & s);
            return *this;
        }
        bool operator!=(const iter) const { return !ed; }
    };
    UINT s;
    all_subset(UINT s) : s(s) {}
    iter begin() const { return iter(s); }
    iter end() const { return iter(0); }
};