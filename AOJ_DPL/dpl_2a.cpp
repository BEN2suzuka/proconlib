// DPL 2_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 巡回セールスマン問題 (TSP : Traveling Salesman Problem)
int main() {
  int V, E; cin >> V >> E;
  const int INF = 1000000007;
  vector<vector<int>> dist(V, vector<int>(V, INF));
  for (int i = 0; i < E; i++) {
    int s, t, d; cin >> s >> t >> d;
    dist.at(s).at(t) = d;
  }
  // dp[S][j] := 訪れた街の集合を S、最後に訪れた街を j としたときの最短距離
  vector<vector<int>> dp(1 << V, vector<int>(V, INF));
  dp.at(1).at(0) = 0;  // 0 を訪れている (0 を出発点とする)
  for (int i = 1; i < (1 << V); i++) {
    for (int j = 0; j < V; j++) {
      if (dp.at(i).at(j) == INF) continue;
      // 次に街 k を訪れる
      for (int k = 0; k < V; k++) {
        if ((i >> k) & 1) continue;  // すでに k を訪れていた場合
        int nexti = i | (1 << k);
        int nextd = dp.at(i).at(j) + dist.at(j).at(k);
        dp.at(nexti).at(k) = min(dp.at(nexti).at(k), nextd);
      }
    }
  }
  int all = (1 << V) - 1;
  int ans = INF;
  for (int j = 0; j < V; j++) {
    int nextd = dp.at(all).at(j) + dist.at(j).at(0);  // 最後に 0 に帰る
    ans = min(ans, nextd);
  }
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}