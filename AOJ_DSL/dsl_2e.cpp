// DSL 2_E
// C++14
#include <bits/stdc++.h>
using namespace std;

// Range Add Query (RAQ)
int num = 1;
vector<int> A;

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
  int N, Q; cin >> N >> Q;
  num = 1;
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  // 要素数 n のときに必要なノード数は 2*n - 1
  A = vector<int>(2*num - 1, 0);
  for (int j = 0; j < Q; j++) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      s--; t--;
      add(s, t+1, x, 0, 0, num);
    }
    else {
      int i; cin >> i;
      i--;
      cout << get(i) << endl;
    }
  }
}