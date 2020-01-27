// DPL 1_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最長増加部分列 (LIS : Longest Increasing Subsequence)
int main() {
  int N; cin >> N;
  const int INF = 1000000007;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  // dp[i] := 長さが i+1 であるような LIS の最終要素の最小値
  vector<int> dp(N, INF);
  for (int i = 0; i < N; i++) {
    // A[i] 以上となる最初の位置を更新
    *lower_bound(dp.begin(), dp.end(), A.at(i)) = A.at(i);
  }
  int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  cout << ans << endl;
}