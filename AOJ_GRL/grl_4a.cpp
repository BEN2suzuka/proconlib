// GRL 4_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 有向グラフの閉路検査
vector<vector<int>> G;
// seen : 行きがけ順で探索済みか
// visited : 帰りがけ順で探索済みか
vector<bool> seen, visited;

bool dfs(int v) {
  seen.at(v) = true;
  for (int nx : G.at(v)) {
    if (seen.at(nx)) {
      if (!visited.at(nx)) return true;  // まだ帰りがけでなければ閉路
      continue;  // すでに帰りがけならば閉路ではない
    }
    if (dfs(nx)) return true;
  }
  visited.at(v) = true;
  return false;
}

int main() {
  int V, E; cin >> V >> E;
  G.resize(V);
  seen.resize(V);
  visited.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    G.at(s).push_back(t);
  }
  bool ans = false;
  for (int i = 0; i < V; i++) {
    if (seen.at(i)) continue;
    if (dfs(i)) ans = true;
  }
  if (ans) cout << 1 << endl;
  else cout << 0 << endl;
}