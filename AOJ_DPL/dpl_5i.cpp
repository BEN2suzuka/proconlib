// DPL 5_I
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別する
// 箱 (K 個) : 区別しない
// 箱の中身は 1 つ以上
// -> スターリング数 S(N, K) = ({K}_Σ_{i=0} (-1)^i {K}_C_{i} (K-i)^N) / K!
// 箱を区別したときの結果を K! で割る

// スターリング数を漸化式で求める
// S(N, 1) = S(N, N) = 1
// S(N, K) = S(N-1, K-1) + K * S(N-1, K)

int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX = 1001;
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
  cout << dp.at(N).at(K) << endl;
}