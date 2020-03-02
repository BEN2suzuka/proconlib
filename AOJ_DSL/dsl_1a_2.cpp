// DSL 1_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// parent[x] := x の親
// ただし、x が根のときは、x が属するグループの要素数 * (-1) を持つ
struct UnionFind {
  vector<int> parent;

  UnionFind(int N = 1) {
    init(N);
  }

  void init(int N = 1) {
    parent.resize(N);
    for (int i = 0; i < N; i++) parent.at(i) = -1;
  }

  int root(int x) {
    if (parent.at(x) < 0) return x;
    return parent.at(x) = root(parent.at(x));
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (parent.at(x) > parent.at(y)) swap(x, y);
    parent.at(x) += parent.at(y);
    parent.at(y) = x;
    return true;
  }

  // x が属するグループの要素数を返す
  int size(int x) {
    return -parent.at(root(x));
  }
};

int main() {
  int N, Q; cin >> N >> Q;
  UnionFind uf(N);
  for (int i = 0; i < Q; i++) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) uf.merge(x, y);
    if (com == 1) {
      if (uf.issame(x, y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}