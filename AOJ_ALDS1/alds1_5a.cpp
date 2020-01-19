// ALDS1 5_A
// C++14
#include <bits/stdc++.h>
using namespace std;

vector<int> A;

// 部分和問題
bool func(int i, int m) {
  if (i == 0) {
    if (m == 0) return true;
    else return false;
  }
  if (func(i-1, m)) return true;  // A[i-1] を足さない場合
  if (func(i-1, m - A.at(i-1))) return true;  // A[i-1] を足す場合
  return false;
}

int main() {
  int N; cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  vector<int> M(Q);
  for (int i = 0; i < Q; i++) cin >> M.at(i);
  for (int i = 0; i < Q; i++) {
    if (func(N, M.at(i))) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}