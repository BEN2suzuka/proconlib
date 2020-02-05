// DPL 5_J
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別しない
// 箱 (K 個) : 区別しない
// 入れ方に制限なし -> 分割数 P(N, K)

// 分割数 P(N, K) : 自然数 N を K 個の非負整数の和で表すときの場合の数
// P(N, K) = P(N, K-1) + P(N-K, K)

int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX = 1001;
  vector<vector<long long>> dp(MAX, vector<long long>(MAX));
  for (int j = 0; j <= N; j++) dp.at(0).at(j) = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i - j >= 0) {
        dp.at(i).at(j) = (dp.at(i).at(j-1) + dp.at(i-j).at(j)) % MOD;
      }
      else {
        dp.at(i).at(j) = dp.at(i).at(j-1);
      }
    }
  }
  cout << dp.at(N).at(K) << endl;
}