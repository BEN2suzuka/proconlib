// ITP2 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // 前の順列
  if (prev_permutation(A.begin(), A.end())) {
    for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
    cout << A.at(N-1) << endl;
  }

  // もとの順列
  next_permutation(A.begin(), A.end());
  for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
  cout << A.at(N-1) << endl;

  // 次の順列
  if (next_permutation(A.begin(), A.end())) {
    for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
    cout << A.at(N-1) << endl;
  }
}