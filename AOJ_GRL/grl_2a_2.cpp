// GRL 2_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小全域木 (MST : Minimum Spanning Tree) : 全域木のうち辺の重みの総和が最小
// クラスカルのアルゴリズム
int V, E;
const int INF = 1000000000;
struct Edge { int s, t, w; };  // 頂点 s と頂点 t を結ぶ重み w の辺
vector<Edge> M;

struct UnionFind {
  vector<int> parent, rank;
  
  UnionFind(int N = 1) {
    init(N);
  }

  void init(int N = 1) {
    parent.resize(N);
    rank.resize(N);
    for (int i = 0; i < N; i++) {
      parent.at(i) = i;
      rank.at(i) = 0;
    }
  }

  int root(int x) {
    if (parent.at(x) == x) return x;
    else {
      int r = root(parent.at(x));
      parent.at(x) = r;
      return r;
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rank.at(x) < rank.at(y)) swap(x, y);
    if (rank.at(x) == rank.at(y)) rank.at(x)++;
    parent.at(y) = x;
  }
};

bool comp(Edge &e1, Edge &e2) {
  return e1.w < e2.w;
}

// 最小全域木の辺の重みの総和を返す
int kruskal() {
  sort(M.begin(), M.end(), comp);  // 辺の重みが小さい順にソート
  UnionFind uf(V);  // Union-Find 木の初期化
  int res = 0;
  for (int i = 0; i < E; i++) {
    Edge e = M.at(i);
    // 頂点 s と頂点 t が同じ連結成分に属していないならば、辺 e を MST に追加
    // 同じ連結成分に属していると、必ず閉路ができてしまう
    // 同じ連結成分かどうかは Union-Find 木で判定
    if (!uf.issame(e.s, e.t)) {
      uf.merge(e.s, e.t);
      res += e.w;
    }
  }
  return res;
}

int main() {
  cin >> V >> E;
  M.resize(E);
  for (int i = 0; i < E; i++) {
    int s, t, w; cin >> s >> t >> w;
    Edge e = { s, t, w };
    M.at(i) = e;
  }
  cout << kruskal() << endl;
}