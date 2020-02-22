// GRL 7_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二部マッチング
int V;  // 頂点数
vector<vector<int>> G;
vector<int> match;  // マッチングのペア
vector<bool> used;

// 増加パスを探す
bool dfs(int v) {
  used.at(v) = true;
  for (int u : G.at(v)) {
    int w = match.at(u);
    // u にはペアがいない (w < 0)
    // または、u にはペアがいて、ペアの相手 w には u 以外で組める頂点が存在
    if (w < 0 || (!used.at(w) && dfs(w))) {
      match.at(v) = u;
      match.at(u) = v;
      return true;
    }
  }
  return false;
}

// 二部グラフの最大マッチングの辺の数を返す
int BipartiteMatching() {
  int res = 0;
  for (int v = 0; v < V; v++) {
    if (match.at(v) < 0) {
      fill(used.begin(), used.end(), false);
      if (dfs(v)) res++;
    }
  }
  return res;
}

int main() {
  int X, Y, E; cin >> X >> Y >> E;
  V = X + Y;
  G.resize(V);
  match.assign(V, -1);
  used.resize(V);
  for (int i = 0; i < E; i++) {
    int x, y; cin >> x >> y;
    G.at(x).push_back(X+y);
    G.at(X+y).push_back(x);
  }
  cout << BipartiteMatching() << endl;
}