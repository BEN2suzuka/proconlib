// ALDS1 6_B
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // パーティション
  int x = A.at(N-1);  // 基準値
  int i = 0;  // 添字 i 以下に x 以下の要素を集める
  for (int j = 0; j < N; j++) {
    if (A.at(j) <= x) {
      swap(A.at(i), A.at(j));
      i++;
    }
  }

  // 出力
  for (int j = 0; j < N; j++) {
    if (j) cout << " ";
    if (j == i-1) cout << "[";
    cout << A.at(j);
    if (j == i-1) cout << "]";
  }
  cout << endl;
}