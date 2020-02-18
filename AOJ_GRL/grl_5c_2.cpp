// GRL 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最小共通祖先 (LCA : Lowest Common Ancestor)
// 根付き木の 2 頂点 u, v の共通祖先で最も根から遠い祖先

vector<vector<int>> G;
const int INF = 2147483647;  // 2^31 - 1

// Euler Tour (DFS 木も作る)
// t := タイマー
// pre[i] := もとの頂点番号 i に対応する DFS 木の頂点番号
// ET[i] := DFS の訪問順をもつ (2*N-1 要素)
// step[i] := 頂点 i を最初に訪問するまでに何歩歩いたか
void dfs(int v, int &t, vector<int> &pre, vector<int> &ET, vector<int> &step) {
  int preOrder = t;
  pre.at(v) = preOrder;
  t++;
  step.at(pre.at(v)) = ET.size();
  ET.push_back(pre.at(v));
  for (auto nx : G.at(v)) {
    dfs(nx, t, pre, ET, step);
    ET.push_back(pre.at(v));
  }
}

// A.at(i) を x に更新
void update(vector<int> &A, int i, int x, int num) {
  i += num - 1;  // ノード番号
  A.at(i) = x;
  while (i > 0) {
    i = (i - 1) / 2;  // 親のノードへ
    A.at(i) = min(A.at(i*2 + 1), A.at(i*2 + 2));
  }
}

// [a, b) の最小値を求める
// ノード番号 k は [l, r) に対応している
int query(vector<int> &A, int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return INF;  // [a, b) と [l, r) が交差していない
  if (a <= l && r <= b) return A.at(k);  // [a, b) が [l, r) を完全に含む
  else {
    int c1 = query(A, a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(A, a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  vector<int> pre(N), ET, step(N);
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int c; cin >> c;
      G.at(i).push_back(c);
    }
  }
  int timer = 0;
  dfs(0, timer, pre, ET, step);
  vector<int> rev(N);  // DFS 木の頂点番号 -> もとの頂点番号
  for (int i = 0; i < N; i++) rev.at(pre.at(i)) = i;
  int num = 1;
  while (num < 2*N-1) num *= 2;
  vector<int> A(2*num - 1, 0);  // EulerTour をセグ木で管理
  for (int i = 0; i < 2*N-1; i++) update(A, i, ET.at(i), num);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    if (u == v) { cout << u << endl; continue; }
    u = pre.at(u);  // DFS 木の頂点番号に変換
    v = pre.at(v);
    if (step.at(u) > step.at(v)) swap(u, v);
    // LCA(i, j) は RMQ[ step[i], step[j] ) (DFS 木の頂点 i < j)
    int c = query(A, step.at(u), step.at(v), 0, 0, num);
    cout << rev.at(c) << endl;
  }
}