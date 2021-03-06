// DSL 2_G
// C++14
#include <bits/stdc++.h>
using namespace std;

// RSQ and RAQ
int num = 1;
vector<pair<long long, long long>> A;  // first: 値, second: 遅延評価値

// ノード番号 k を遅延評価する (A.at(k).first を正しい値に)
void eval(int k, int l, int r) {
  A.at(k).first += A.at(k).second;
  if (r - l > 1) {
    A.at(2*k+1).second += A.at(k).second / 2;
    A.at(2*k+2).second += A.at(k).second / 2;
  }
  A.at(k).second = 0;
}

// [a, b) の要素に x を加算
// ノード番号 k は [l, r) に対応している
void add(int a, int b, int x, int k, int l, int r) {
  eval(k, l, r);
  // [a, b) と [l, r) が交差していない
  if (r <= a || b <= l) return;
  // [a, b) が [l, r) を完全に含む
  if (a <= l && r <= b) {
    A.at(k).second = x * (r - l);
    eval(k, l, r);
  }
  else {
    add(a, b, x, 2*k+1, l, (l+r)/2);
    add(a, b, x, 2*k+2, (l+r)/2, r);
    A.at(k).first = A.at(2*k+1).first + A.at(2*k+2).first;
  }
}

// [a, b) の合計値を返す
long long query(int a, int b, int k, int l, int r) {
  eval(k, l, r);
  if (r <= a || b <= l) return 0;
  if (a <= l && r <= b) return A.at(k).first;
  else {
    long long c1 = query(a, b, 2*k+1, l, (l+r)/2);
    long long c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return c1 + c2;
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  num = 1;
  while (num < N) num *= 2;  // 要素数は 2 のべき乗にする
  // 要素数 n のときに必要なノード数は 2*n - 1
  A = vector<pair<long long, long long>>(2*num - 1, make_pair(0, 0));
  for (int j = 0; j < Q; j++) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      s--; t--;
      add(s, t+1, x, 0, 0, num);
    }
    else {
      int s, t; cin >> s >> t;
      s--; t--;
      cout << query(s, t+1, 0, 0, num) << endl;
    }
  }
}