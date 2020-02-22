// DSL 1_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 重み付き Union Find 木
struct WeightedUnionFind {
  vector<int> parent, rank, diff_weight;

  WeightedUnionFind(int N = 1) {
    init(N);
  }

  void init(int N = 1) {
    parent.resize(N);
    rank.resize(N);
    diff_weight.resize(N);
    for (int i = 0; i < N; i++) {
      parent.at(i) = i;
      rank.at(i) = 0;
      diff_weight.at(i) = 0;
    }
  }

  int root(int x) {
    if (parent.at(x) == x) return x;
    else {
      int r = root(parent.at(x));
      diff_weight.at(x) += diff_weight.at(parent.at(x));
      parent.at(x) = r;
      return r;
    }
  }

  int weight(int x) {
    root(x);
    return diff_weight.at(x);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // ノード y はノード x より w 重い
  bool merge(int x, int y, int w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (rank.at(x) < rank.at(y)) {
      swap(x, y);
      w = -w;
    }
    if (rank.at(x) == rank.at(y)) rank.at(x)++;
    parent.at(y) = x;
    diff_weight.at(y) = w;
    return true;
  }

  int diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

int main() {
  int N, Q; cin >> N >> Q;
  WeightedUnionFind uf(N);
  for (int i = 0; i < Q; i++) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      int z; cin >> z;
      uf.merge(x, y, z);
    }
    if (com == 1) {
      if (uf.issame(x, y)) cout << uf.diff(x, y) << endl;
      else cout << "?" << endl;
    }
  }
}