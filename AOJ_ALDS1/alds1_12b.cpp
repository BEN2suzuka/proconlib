// ALDS1 12_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 単一始点最短経路
int N;
const int INF = 1000000000;
vector<vector<int>> M;

// ダイクストラのアルゴリズム (負の重みの辺を含むグラフには適用できない)
void dijkstra() {
  vector<int> color(N);
  vector<int> d(N, INF);  // スタート地点からのコスト
  vector<int> p(N, -1);  // この問題では不要
  color.at(0) = 1;
  d.at(0) = 0;

  while (1) {
    int u = -1;
    int mincost = INF;
    // 最短経路木に追加する候補からコスト最小の頂点 u を取り出す
    for (int i = 0; i < N; i++) {
      if (d.at(i) < mincost && color.at(i) == 1) {
        u = i;
        mincost = d.at(i);
      }
    }
    if (u == -1) break;
    color.at(u) = 2;  // 最短経路木に追加

    // u に隣接する頂点を候補に追加
    for (int v = 0; v < N; v++) {
      if (color.at(v) != 2 && M.at(u).at(v) != INF) {
        if (d.at(u) + M.at(u).at(v) < d.at(v)) {
          d.at(v) = d.at(u) + M.at(u).at(v);
          color.at(v) = 1;
          p.at(v) = u;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << i << " " << d.at(i) << endl;
  }
}

int main() {
  cin >> N;
  M = vector<vector<int>>(N, vector<int>(N, INF));
  for (int i = 0; i < N; i++) {
    int u, k; cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c; cin >> v >> c;
      M.at(u).at(v) = c;
    }
  }
  dijkstra();
}