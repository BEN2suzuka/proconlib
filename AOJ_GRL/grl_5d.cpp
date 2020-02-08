// GRL 5_D
// C++14
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> pre;  // pre[i] := もとの頂点番号 i に対応する DFS 木の頂点番号
vector<int> parent;  // parent[i] := DFS 木の頂点 i の親
vector<int> pos;  // pos[i] := DFS 木の頂点 i の子孫が DFS を終えたときの timer
int timer = 0;
int num = 1;
vector<int> A;  // A[i] := DFS 木における、根から i までの間にある辺の重みの総和

// DFS 木を作る
void dfs(int v) {
  int preOrder = timer;
  pre.at(v) = preOrder;
  timer++;
  for (auto nx : G.at(v)) {
    parent.at(timer) = preOrder;
    dfs(nx);
  }
  pos.at(preOrder) = timer;
}

// A.at(i) を返す
int get(int i) {
  i += num - 1;  // ノード番号
  int res = A.at(i);
  while (i > 0) {
    i = (i - 1) / 2;  // 親のノードへ
    res += A.at(i);
  }
  return res;
}

// [a, b) の要素に x を加算
// ノード番号 k は [l, r) に対応している
void add(int a, int b, int x, int k, int l, int r) {
  // [a, b) と [l, r) が交差していない
  if (r <= a || b <= l) return;
  // [a, b) が [l, r) を完全に含む
  if (a <= l && r <= b) A.at(k) += x;
  else {
    add(a, b, x, 2*k+1, l, (l+r)/2);
    add(a, b, x, 2*k+2, (l+r)/2, r);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  pre.resize(N);
  parent.resize(N);
  pos.resize(N);
  for (int i = 0; i < N; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int c; cin >> c;
      G.at(i).push_back(c);
    }
  }
  dfs(0);  // もとの頂点 0 を根とした DFS 木を作る
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  // 要素数 n のときに必要なノード数は 2*n - 1
  A = vector<int>(2*num - 1, 0);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int com; cin >> com;
    if (com == 0) {
      int v, w; cin >> v >> w;
      // 区間 [ pre.at(v), pos.at(pre.at(v)) ) に w を加算
      // pre[v] を根とする部分木の各頂点に w を加算
      add(pre.at(v), pos.at(pre.at(v)), w, 0, 0, num);
    }
    else {
      int u; cin >> u;
      int v = pre.at(u);
      cout << get(v) << endl;  // 根から v までの辺の総和を返す
    }
  }
}