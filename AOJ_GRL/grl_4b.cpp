// GRL 4_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// トポロジカルソート (深さ優先探索)
vector<vector<int>> G;
vector<bool> visited;
vector<int> order;

void dfs(int v) {
  visited.at(v) = true;
  for (int nx : G.at(v)) {
    if (visited.at(nx)) continue;
    dfs(nx);
  }
  order.push_back(v);
}

int main() {
  int V, E; cin >> V >> E;
  G.resize(V);
  visited.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    G.at(s).push_back(t);
  }
  for (int i = 0; i < V; i++) {
    if (visited.at(i)) continue;
    dfs(i);  // 未訪問の頂点を起点
  }
  reverse(order.begin(), order.end());
  for (int i = 0; i < V; i++) cout << order.at(i) << endl;
}