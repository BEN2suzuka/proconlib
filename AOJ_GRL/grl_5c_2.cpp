// GRL 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小共通祖先 (LCA : Lowest Common Ancestor)
// 根付き木の 2 頂点 u, v の共通祖先で最も根から遠い祖先

// Euler Tour
vector<vector<int>> G;
vector<int> pre;  // pre[i] := 頂点 i を最初に訪問するまでに何歩歩いたか
vector<int> EulerTour;  // DFS の訪問順をもつ (2*N-1 要素)
vector<int> A;  // EulerTour をセグ木でもつ
int num = 1;
const int INF = 2147483647;  // 2^31 - 1

// Euler Tour
void dfs(int v) {
  pre.at(v) = EulerTour.size();
  EulerTour.push_back(v);
  for (auto nx : G.at(v)) {
    dfs(nx);
    EulerTour.push_back(v);
  }
}

// A.at(i) を x に更新
void update(int i, int x) {
  i += num - 1;  // ノード番号
  A.at(i) = x;
  while (i > 0) {
    i = (i - 1) / 2;  // 親のノードへ
    A.at(i) = min(A.at(i*2 + 1), A.at(i*2 + 2));
  }
}

// [a, b) の最小値を求める
// ノード番号 k は [l, r) に対応している
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INF;  // [a, b) と [l, r) が交差していない
  if (a <= l && r <= b) return A.at(k);  // [a, b) が [l, r) を完全に含む
  else {
    int c1 = query(a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  pre.resize(N);
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int c; cin >> c;
      G.at(i).push_back(c);
    }
  }
  dfs(0);
  while (num < 2*N-1) num *= 2;
  A = vector<int>(2*num - 1, 0);
  for (int i = 0; i < 2*N-1; i++) update(i, EulerTour.at(i));
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    if (u == v) { cout << u << endl; continue; }
    if (pre.at(u) > pre.at(v)) swap(u, v);
    // LCA(i, j) は RMQ[ pre[i], pre[j] ) (i < j)
    cout << query(pre.at(u), pre.at(v), 0, 0, num) << endl;
  }
}