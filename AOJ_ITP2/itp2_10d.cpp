// ITP2 10_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<bitset<64>> mask(N);
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int pos; cin >> pos;
      mask.at(i).set(pos);
    }
  }

  bitset<64> b(0);
  int Q; cin >> Q;
  for (int j = 0; j < Q; j++) {
    int q, m; cin >> q >> m;
    if (q == 0) cout << b.test(m) << endl;
    // マスクが表す部分のフラグを ON に
    if (q == 1) b |= mask.at(m);
    // マスクが表す部分のフラグを OFF に
    if (q == 2) b &= ~mask.at(m);
    // マスクが表す部分のフラグを反転
    if (q == 3) b ^= mask.at(m);
    // マスクが表す部分の全てのフラグが ON か
    if (q == 4) cout << ((b & mask.at(m)) == mask.at(m)) << endl;
    // マスクが表す部分のいずれかのフラグが ON か
    if (q == 5) cout << (b & mask.at(m)).any() << endl;
    // マスクが表す部分の全てのフラグが OFF か
    if (q == 6) cout << (b & mask.at(m)).none() << endl;
    // マスクが表す部分の ON になっているフラグの数
    if (q == 7) cout << (b & mask.at(m)).count() << endl;
    // マスクが表す部分の整数値
    if (q == 8) cout << (b & mask.at(m)).to_ullong() << endl;
  }
}