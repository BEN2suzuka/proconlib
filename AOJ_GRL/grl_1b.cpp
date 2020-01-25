// GRL 1_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// ベルマン・フォード
// 負の閉路がない限り、負の重みを持つ辺が存在しても問題ない
int V, E;
const int INF = 1000000000;
struct Edge { int from, to, cost; };
vector<Edge> M;
vector<int> d;

bool Bellman(int r) {
  d.at(r) = 0;  // スタート地点
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < E; j++) {
      Edge e = M.at(j);
      if (d.at(e.from) == INF) continue;
      if (d.at(e.from) + e.cost < d.at(e.to)) {
        d.at(e.to) = d.at(e.from) + e.cost;
        if (i == V-1) return true;  // 負の閉路あり
      }
    }
  }
  return false;
}

int main() {
  int r;
  cin >> V >> E >> r;
  M.resize(E);
  d.assign(V, INF);
  for (int i = 0; i < E; i++) {
    int s, t, d; cin >> s >> t >> d;
    M.at(i) = { s, t, d };
  }

  if (Bellman(r)) {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else {
    for (int i = 0; i < V; i++) {
      if (d.at(i) != INF) cout << d.at(i) << endl;
      else cout << "INF" << endl;
    }
  }
}