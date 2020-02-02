// GRL 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小共通祖先 (LCA : Lowest Common Ancestor)
// 根付き木の 2 頂点 u, v の共通祖先で最も根から遠い祖先
vector<vector<int>> G;
vector<vector<int>> parent;  // parent[k][v] v から親へ 2^k 回辿った頂点 (無ければ -1)
vector<int> depth;  // 根からの深さ
const int K = 17;

// parent[0][v] と depth[v] を埋める
void dfs(int cur, int par, int dep) {
  parent.at(0).at(cur) = par;
  depth.at(cur) = dep;
  for (int nx : G.at(cur)) {
    if (nx == par) continue;
    dfs(nx, cur, dep + 1);
  }
}

// parent[k][v] を埋める
void doubling(int N) {
  for (int k = 0; k < K-1; k++) {
    for (int v = 0; v < N; v++) {
      if (parent.at(k).at(v) < 0) parent.at(k+1).at(v) = -1;
      else parent.at(k+1).at(v) = parent.at(k).at(parent.at(k).at(v));
    }
  }
}

// u と v の LCA を返す
int lca(int u, int v) {
  // u と v の深さが同じになるまで親を辿る
  if (depth.at(u) > depth.at(v)) swap(u, v);
  for (int k = 0; k < K; k++) {
    if ((depth.at(v) - depth.at(u) >> k & 1)) v = parent.at(k).at(v);
  }
  if (u == v) return u;
  // 二分探索で LCA を求める
  for (int k = K-1; k >= 0; k--) {
    if (parent.at(k).at(u) != parent.at(k).at(v)) {
      u = parent.at(k).at(u);
      v = parent.at(k).at(v);
    }
  }
  return parent.at(0).at(u);
}

int main() {
  int N; cin >> N;
  G.resize(N);
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int c; cin >> c;
      G.at(i).push_back(c);
      G.at(c).push_back(i);
    }
  }
  parent = vector<vector<int>>(K, vector<int>(N));
  depth.resize(N);
  dfs(0, -1, 0);
  doubling(N);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << endl;
  }
}