// DPL 5_G
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別する
// 箱 (K 個) : 区別しない
// 入れ方に制限なし
// <=> N 個のボールを K 個以下のグループに分ける
// -> ベル数 B(N, K) = S(N, 0) + S(N, 1) + ... + S(N, K)

// スターリング数 S(N, K) : N 個のボールを K 個のグループに分ける
// S(N, 1) = S(N, N) = 1
// S(N, K) = S(N-1, K-1) + K * S(N-1, K)

int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX = 1001;
  // スターリング数
  vector<vector<long long>> dp(MAX, vector<long long>(MAX));
  for (int i = 1; i <= N; i++) dp.at(i).at(1) = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      if (j != 1) {
        dp.at(i+1).at(j) = (dp.at(i+1).at(j) + j * dp.at(i).at(j)) % MOD;
      }
      if (j != K) {
        dp.at(i+1).at(j+1) = (dp.at(i+1).at(j+1) + dp.at(i).at(j)) % MOD;
      }
    }
  }
  // ベル数を計算
  long long ans = 0;
  for (int j = 0; j <= K; j++) ans = (ans + dp.at(N).at(j)) % MOD;
  cout << ans << endl;
}