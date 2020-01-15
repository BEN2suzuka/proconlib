// ALDS1 2_B
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // 選択ソート
  // i : 未ソート部分の先頭を指すループ変数
  // minj : 最小のものの位置
  // j : 未ソート部分から最小値の位置を探すためのループ変数
  int minj;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A.at(j) < A.at(minj)) minj = j;
    }
    if (minj != i) {
      swap(A.at(i), A.at(minj));
      cnt++;
    }
  }

  // 出力
  for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
  cout << A.at(N-1) << endl;
  cout << cnt << endl;
}