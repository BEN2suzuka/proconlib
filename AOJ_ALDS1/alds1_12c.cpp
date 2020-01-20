// ALDS1 12_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 単一始点最短経路
int N;
const int INF = 1000000000;
vector<vector<pair<int, int>>> M;  // first : 頂点, second : 有向辺の重み

// ダイクストラのアルゴリズム (優先度付きキューの利用)
void dijkstra() {
  // first : スタート地点からのコスト, second : 頂点
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
  vector<int> color(N);
  vector<int> d(N, INF);
  vector<int> p(N, -1);  // この問題では不要
  color.at(0) = 1;
  d.at(0) = 0;
  PQ.push(make_pair(0, 0));

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

  for (int i = 0; i < N; i++) {
    cout << i << " " << d.at(i) << endl;
  }
}

int main() {
  cin >> N;
  M.resize(N);
  for (int i = 0; i < N; i++) {
    int u, k; cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c; cin >> v >> c;
      M.at(u).push_back(make_pair(v, c));  // 隣接リスト表現
    }
  }
  dijkstra();
}