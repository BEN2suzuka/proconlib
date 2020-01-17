// ITP2 11_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  int T = 0;  // 集合 T
  for (int i = 0; i < K; i++) {
    int b; cin >> b;
    T |= (1 << b);
  }
  // U の部分集合を全探索
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    if ((T & tmp) != T) continue;  // T を部分集合として持っているか
    cout << tmp << ":";
    for (int i = 0; i < N; i++) {
      if ((tmp >> i) & 1) cout << " " << i;
    }
    cout << endl;
  }
}