// DPL 5_K
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別しない (しても同じ)
// 箱 (K 個) : 区別しない
// 箱の中身は 1 つ以下 -> 1 or 0
int main() {
  int N, K; cin >> N >> K;
  if (N > K) cout << 0 << endl;
  else cout << 1 << endl;
}