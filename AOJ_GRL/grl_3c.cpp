// GRL 3_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 強連結成分分解
int V;
vector<vector<int>> G, rG;
vector<int> order;  // 帰りがけ順
vector<int> group;
vector<bool> visited;

void dfs(int v) {
  visited.at(v) = true;
  for (int nx : G.at(v)) {
    if (!visited.at(nx)) dfs(nx);
  }
  order.push_back(v);
}

void rdfs(int v, int k) {
  group.at(v) = k;
  visited.at(v) = true;
  for (int nx : rG.at(v)) {
    if (!visited.at(nx)) rdfs(nx, k);
  }
}

int main() {
  int E; cin >> V >> E;
  G.resize(V);
  rG.resize(V);
  group.resize(V);
  visited.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    G.at(s).push_back(t);
    rG.at(t).push_back(s);
  }
  for (int i = 0; i < V; i++) {
    if (!visited.at(i)) dfs(i);
  }
  visited.assign(V, false);
  int k = 0;
  for (int i = order.size()-1; i >= 0; i--) {
    if (!visited.at(order.at(i))) {
      rdfs(order.at(i), k);
      k++;
    }
  }
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    cout << (group.at(u) == group.at(v)) << endl;
  }
}