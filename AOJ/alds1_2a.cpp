// ALDS1 2_A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // バブルソート
  // i : 未ソート部分列の先頭を指すループ変数
  // j : 未ソート部分の隣り合う要素を比較するためのループ変数
  bool flag = true;
  int i = 0;
  int cnt = 0;
  while (flag) {
    flag = false;
    for (int j = N-1; j >= i+1; j--) {
      if (A.at(j) < A.at(j-1)) {
        swap(A.at(j), A.at(j-1));
        cnt++;
        flag = true;
      }
    }
    i++;
  }

  // 出力
  for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
  cout << A.at(N-1) << endl;
  cout << cnt << endl;
}