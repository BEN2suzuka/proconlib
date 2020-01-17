// ITP2 11_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  // bit 全探索
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    cout << tmp << ":";
    // N 桁の bit 列を 1 桁ずつ走査
    for (int i = 0; i < N; i++) {
      // i 番目の bit が立っているか
      if ((tmp >> i) & 1) cout << " " << i;
    }
    cout << endl;
  }
}

// 入力
// 3
// 出力
// 0:
// 1: 0
// 2: 1
// 3: 0 1
// 4: 2
// 5: 0 2
// 6: 1 2
// 7: 0 1 2