// ALDS1 9_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分ヒープ
int parent(int i) { return i / 2; }  // 親
int left(int i) { return 2 * i; }  // 左の子
int right(int i) { return 2 * i + 1; }  // 右の子

int main() {
  int N; cin >> N;
  vector<int> A(N+1);  // 1-indexed
  for (int i = 1; i <= N; i++) cin >> A.at(i);
  for (int i = 1; i <= N; i++) {
    cout << "node " << i << ": key = " << A.at(i) << ", ";
    if (parent(i) >= 1) cout << "parent key = " << A.at(parent(i)) << ", ";
    if (left(i) <= N) cout << "left key = " << A.at(left(i)) << ", ";
    if (right(i) <= N) cout << "right key = " << A.at(right(i)) << ", ";
    cout << endl;
  }
}

// 入力
// 5
// 7 8 1 2 3
// 出力結果
// node 1: key = 7, left key = 8, right key = 1,
// node 2: key = 8, parent key = 7, left key = 2, right key = 3,
// node 3: key = 1, parent key = 7,
// node 4: key = 2, parent key = 8,
// node 5: key = 3, parent key = 8,