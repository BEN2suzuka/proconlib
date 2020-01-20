// ALDS1 11_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 連結グラフ
int N;
vector<vector<int>> G;
vector<int> C;  // 色

void dfs(int cur, int color) {
  C.at(cur) = color;
  for (int nx : G.at(cur)) {
    if (C.at(nx) != -1) continue;
    dfs(nx, color);
  }
}

int main() {
  cin >> N;
  int M; cin >> M;
  G.resize(N);
  C.assign(N, -1);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G.at(u).push_back(v);
    G.at(v).push_back(u);
  }

  int color = 0;
  for (int i = 0; i < N; i++) {
    if (C.at(i) == -1) {
      dfs(i, color);
      color++;
    }
  }

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    if (C.at(u) == C.at(v)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}