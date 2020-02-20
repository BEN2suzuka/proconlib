// ALDS1 10_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 連鎖行列積 (区間 DP)
int main() {
  int N; cin >> N;
  vector<int> p(N+1);
  for (int i = 1; i <= N; i++) cin >> p.at(i-1) >> p.at(i);
  const int INF = 1000000007;
  // dp[i][j] := M_i M_i+1 ... M_j の掛け算の回数の最小値
  vector<vector<int>> dp(N+1, vector<int>(N+1, INF));
  for (int i = 1; i <= N; i++) dp.at(i).at(i) = 0;
  // 行列の個数 2 個, 3 個, ... と増やしていく
  for (int length = 2; length <= N; length++) {
    for (int i = 1; i <= N - length + 1; i++) {
      int j = i + length - 1;
      for (int k = i; k <= j-1; k++) {
        // M_i ... M_k と M_k+1 ... M_j の掛け算の回数
        int tmp = dp.at(i).at(k) + dp.at(k+1).at(j) + p.at(i-1) * p.at(k) * p.at(j);
        dp.at(i).at(j) = min(dp.at(i).at(j), tmp);
      }
    }
  }
  cout << dp.at(1).at(N) << endl;
}