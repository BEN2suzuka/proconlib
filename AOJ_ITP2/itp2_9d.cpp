// ITP2 9_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> A, B, C;
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    A.insert(a);
  }
  int M; cin >> M;
  for (int i = 0; i < M; i++) {
    int b; cin >> b;
    B.insert(b);
  }
  // 対称差 (A と B はソート済)
  set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.end()));
  for (auto s : C) cout << s << endl;
}