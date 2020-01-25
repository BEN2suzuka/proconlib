// GRL 1_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// ダイクストラ
// 負の重みの辺を含むグラフには適用できない
int V;
const int INF = 1000000000;
vector<vector<pair<int, int>>> M;  // first : 頂点, second : 有向辺の重み

void dijkstra(int r) {
  // first : スタート地点からのコスト, second : 頂点
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
  vector<int> color(V);
  vector<int> d(V, INF);
  vector<int> p(V, -1);  // この問題では不要
  color.at(r) = 1;
  d.at(r) = 0;
  PQ.push(make_pair(0, r));

  while (!PQ.empty()) {
    // 最短経路木に追加する候補からコスト最小の頂点 u を取り出す
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    color.at(u) = 2;  // 最短経路木に追加

    if (d.at(u) < f.first) continue;

    // u に隣接する頂点を候補に追加
    for (auto cand : M.at(u)) {
      int v = cand.first;
      if (color.at(v) == 2) continue;
      if (d.at(u) + cand.second < d.at(v)) {
        d.at(v) = d.at(u) + cand.second;
        PQ.push(make_pair(d.at(v), v));
        color.at(v) = 1;
        p.at(v) = u;
      }
    }
  }

  for (int i = 0; i < V; i++) {
    if (d.at(i) != INF) cout << d.at(i) << endl;
    else cout << "INF" << endl;
  }
}

int main() {
  int E, r;
  cin >> V >> E >> r;
  M.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t, d; cin >> s >> t >> d;
    M.at(s).push_back(make_pair(t, d));  // 有向辺
  }
  dijkstra(r);
}