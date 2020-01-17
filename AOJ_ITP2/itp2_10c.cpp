// ITP2 10_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  bitset<64> b(0);  // 00000...000
  int Q; cin >> Q;
  for (int j = 0; j < Q; j++) {
    int q; cin >> q;
    int i;
    if (0 <= q && q <= 3) cin >> i;
    if (q == 0) cout << b.test(i) << endl;  // 1 かどうか
    if (q == 1) b.set(i);  // 1 に
    if (q == 2) b.reset(i);  // 0 に
    if (q == 3) b.flip(i);  // 反転
    if (q == 4) cout << b.all() << endl;  // 全て 1 か
    if (q == 5) cout << b.any() << endl;  // 1 つでも 1 があるか
    if (q == 6) cout << b.none() << endl;  // 全て 0 か
    if (q == 7) cout << b.count() << endl;  // 1 の個数
    if (q == 8) cout << b.to_ullong() << endl;  // 10 進数の整数に
  }
}