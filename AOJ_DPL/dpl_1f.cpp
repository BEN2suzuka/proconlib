// DPL 1_F
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W; cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++) cin >> v.at(i) >> w.at(i);
  const int INF = 1000000007;
  vector<vector<int>> dp(N+1, vector<int>(N*100+1, INF));
  dp.at(0).at(0) = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N*100; j++) {
      dp.at(i+1).at(j) = min(dp.at(i+1).at(j), dp.at(i).at(j));
      if (j + v.at(i) > N*100) continue;
      dp.at(i+1).at(j + v.at(i)) = min(dp.at(i+1).at(j + v.at(i)), dp.at(i).at(j) + w.at(i));
    }
  }
  int ans = 0;
  for (int j = 0; j <= N*100; j++) {
    if (dp.at(N).at(j) <= W) ans = j;
  }
  cout << ans << endl;
}