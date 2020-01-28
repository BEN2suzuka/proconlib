// DSL 2_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// Range Update Query (RUQ)
int num = 1;
vector<pair<int, int>> A;  // first : 値, second : 時刻
const int INF = 2147483647;  // 2^31 - 1

// A.at(i) を返す
int find(int i) {
  i += num - 1;  // ノード番号
  pair<int, int> res = A.at(i);
  while (i > 0) {
    i = (i - 1) / 2;  // 親のノードへ
    if (res.second < A.at(i).second) res = A.at(i);  // 時刻の遅い方を採用
  }
  return res.first;
}

// [a, b) の要素を x に変更
// t は時刻で、最新の更新ほど t は大きい値をとるようにする
// ノード番号 k は [l, r) に対応している
void update(int a, int b, int x, int t, int k, int l, int r) {
  // [a, b) と [l, r) が公差していない
  if (r <= a || b <= l) return;
  // [a, b) が [l, r) を完全に含む
  if (a <= l && r <= b) A.at(k) = make_pair(x, t);
  else {
    update(a, b, x, t, 2*k+1, l, (l+r)/2);
    update(a, b, x, t, 2*k+2, (l+r)/2, r);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  num = 1;
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  // 要素数 n のときに必要なノード数は 2*n - 1
  A = vector<pair<int, int>>(2*num - 1, make_pair(INF, -1));
  for (int j = 0; j < Q; j++) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      update(s, t+1, x, j, 0, 0, num);  // [s, t]
    }
    else {
      int i; cin >> i;
      cout << find(i) << endl;
    }
  }
}