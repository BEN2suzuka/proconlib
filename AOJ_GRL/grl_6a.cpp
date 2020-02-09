// GRL 6_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最大流問題
const int INF = 1000000007;
struct Edge { int to, cap, rev; };  // 行き先, 容量, 逆辺(index)
vector<vector<Edge>> G;
vector<bool> used;

// from から to へ向かう辺 (容量 cap) をグラフに追加
void addEdge(int from, int to, int cap) {
  Edge e1 = { to, cap, (int)G.at(to).size() };
  G.at(from).push_back(e1);
  Edge e2 = { from, 0, (int)G.at(from).size() - 1 };
  G.at(to).push_back(e2);
}

// 増加パスを 1 つ見つけて、流量を返す
int dfs(int v, int t, int f) {
  if (v == t) return f;  // ゴールに到着
  used.at(v) = true;  // 訪問済み
  for (auto &e : G.at(v)) {
    // まだ容量の残っている隣接頂点に流したい
    if (!used.at(e.to) && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G.at(e.to).at(e.rev).cap += d;
        return d;
      }
    }
  }
  return 0;  // 増加パスが存在しない
}

// 始点 s、終点 t の最大流を返す
int maxFlow(int s, int t) {
  int flow = 0;
  while (true) {
    fill(used.begin(), used.end(), false);
    int f = dfs(s, t, INF);  // 増加パスを 1 つ見つける
    if (f == 0) return flow;  // 増加パスが存在しない
    flow += f;
  }
}

int main() {
  int V, E; cin >> V >> E;
  G.resize(V);
  used.resize(V);
  for (int i = 0; i < E; i++) {
    int u, v, c; cin >> u >> v >> c;
    addEdge(u, v, c);
  }
  cout << maxFlow(0, V-1) << endl;
}