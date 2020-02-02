// DPL 5_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別する
// 箱 (K 個) : 区別する
// 箱の中身は 1 つ以下 -> {K}_P_{N}
int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = (ans * K) % MOD;
    K--;
  }
  cout << ans << endl;
}