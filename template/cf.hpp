#pragma once

#ifdef FASTIO

#ifdef MULTI_TEST
#define MAIN int main() { INT(t); while (t--) solve(); }
#else
#define MAIN int main() { solve(); }
#endif

#else

#ifdef MULTI_TEST
#define MAIN int main() { SYNC_OFF int t; std::cin >> t; while (t--) {  solve(); } }
#else
#define MAIN int main() { SYNC_OFF solve(); }
#endif

#endif

#include "io.hpp"
#ifdef FASTIO
void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#endif