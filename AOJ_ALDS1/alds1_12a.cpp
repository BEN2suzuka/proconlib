// ALDS1 12_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小全域木 (MST : Minimum Spanning Tree) : 全域木のうち辺の重みの総和が最小
const int INF = 1000000000;
vector<vector<int>> M;

// プリムのアルゴリズム
int prim(int N) {
  vector<int> color(N);  // 0 : 未訪問, 1 : MST の候補, 2 : MST
  vector<int> d(N, INF);
  vector<int> p(N, -1);  // p[v] : MST における頂点 v の親 (どこから v に来たか)
  color.at(0) = 1;
  d.at(0) = 0;

  while (1) {
    int u = -1;  // MST に追加する頂点
    int mincost = INF;
    // MST の候補のうち d が最小の頂点 u を探す
    for (int i = 0; i < N; i++) {
      if (d.at(i) < mincost && color.at(i) == 1) {
        u = i;
        mincost = d.at(i);
      }
    }
    if (u == -1) break;  // 全頂点訪問済み
    color.at(u) = 2;  // u を MST に追加

    for (int v = 0; v < N; v++) {
      // u に隣接する頂点を候補に追加
      if (color.at(v) != 2 && M.at(u).at(v) != INF) {
        if (M.at(u).at(v) < d.at(v)) {
          d.at(v) = M.at(u).at(v);
          p.at(v) = u;  // u から来た
          color.at(v) = 1;  // 候補に追加
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (p.at(i) != -1) sum += M.at(i).at(p.at(i));
  }
  return sum;
}

int main() {
  int N; cin >> N;
  M = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int e; cin >> e;
      M.at(i).at(j) = (e == -1) ? INF : e;
    }
  }
  cout << prim(N) << endl;
}