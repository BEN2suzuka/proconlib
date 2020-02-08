// GRL 2_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小全域木 (MST : Minimum Spanning Tree) : 全域木のうち辺の重みの総和が最小
int V;
const int INF = 1000000000;
vector<vector<pair<int, int>>> M;  // first: 頂点, second: 辺の重み

// プリムのアルゴリズム
int prim() {
  // first: d[i], second: 頂点
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
  vector<int> color(V);  // 0: 未訪問, 1: MST の候補, 2: MST
  vector<int> d(V, INF);
  vector<int> p(V, -1);  // p[v] : MST における頂点 v の親 (どこから v に来たか)
  color.at(0) = 1;
  d.at(0) = 0;
  PQ.push(make_pair(d.at(0), 0));
  int sum = 0;

  while (!PQ.empty()) {
    // MST の候補のうち d が最小の頂点 u を探す
    pair<int, int> f = PQ.top();
    PQ.pop();
    int u = f.second;
    if (color.at(u) == 2) continue;
    color.at(u) = 2;  // u を MST に追加
    sum += f.first;

    for (auto cand : M.at(u)) {
      // u に隣接する頂点 v を MST の候補に追加
      int v = cand.first;
      if (color.at(v) == 2) continue;
      if (cand.second < d.at(v)) {
        d.at(v) = cand.second;
        p.at(v) = u;
        color.at(v) = 1;
        PQ.push(make_pair(d.at(v), v));
      }
    }
  }
  return sum;
}

int main() {
  int E;
  cin >> V >> E;
  M.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t, w; cin >> s >> t >> w;
    M.at(s).push_back(make_pair(t, w));
    M.at(t).push_back(make_pair(s, w));
  }
  cout << prim() << endl;
}