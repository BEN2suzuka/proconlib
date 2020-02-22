// DSL 1_A
// C++14
#include <bits/stdc++.h>
using namespace std;

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

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (rank.at(x) < rank.at(y)) swap(x, y);
    if (rank.at(x) == rank.at(y)) rank.at(x)++;
    parent.at(y) = x;
    return true;
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