// DSL 2_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// Range Minimum Query (RMQ)
int num = 1;
vector<int> A;
const int INF = 2147483647;  // 2^31 - 1

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
  if (r <= a || b <= l) return INF;  // [a, b) と [l, r) が公差していない
  if (a <= l && r <= b) return A.at(k);  // [a, b) が [l, r) を完全に含む
  else {
    int c1 = query(a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  num = 1;
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  A = vector<int>(2*num - 1, INF);  // 要素数 n のときに必要なノード数は 2*n - 1
  for (int i = 0; i < Q; i++) {
    int com; cin >> com;
    int x, y; cin >> x >> y;
    if (com == 0) update(x, y);
    else cout << query(x, y+1, 0, 0, num) << endl;  // [x, y] の最小値
  }
}