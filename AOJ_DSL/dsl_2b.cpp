// DSL 2_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// Range Sum Query (RSQ)
int num = 1;
vector<int> A;
const int INF = 2147483647;  // 2^31 - 1

// A.at(i) に x を加算
void add(int i, int x) {
  i += num - 1;  // ノード番号
  A.at(i) += x;
  while (i > 0) {
    i = (i - 1) / 2;  // 親のノードへ
    A.at(i) += x;
  }
}

// [a, b) の和を求める
// ノード番号 k は [l, r) に対応している
int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return 0;  // [a, b) と [l, r) が交差していない
  if (a <= l && r <= b) return A.at(k);  // [a, b) が [l, r) を完全に含む
  else {
    int c1 = query(a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return c1 + c2;
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  num = 1;
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  A = vector<int>(2*num - 1, 0);  // 要素数 n のときに必要なノード数は 2*n - 1
  for (int i = 0; i < Q; i++) {
    int com; cin >> com;
    if (com == 0) {
      int x, y; cin >> x >> y;
      x--;
      add(x, y);
    }
    else {
      int x, y; cin >> x >> y;
      x--; y--;
      cout << query(x, y+1, 0, 0, num) << endl;  // [x, y] の和
    }
  }
}