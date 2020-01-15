// ALDS1 1_A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // 挿入ソート
  // i : 未ソートの部分列の先頭を示すループ変数
  // v : A.at(i) の値を一時的に保存しておくための変数
  // j : ソート済み部分列から v を挿入するための位置を探すループ変数
  for (int i = 0; i < N; i++) {
    int v = A.at(i);
    int j = i-1;
    while (j >= 0 && A.at(j) > v) {
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;

    // 出力
    for (int k = 0; k < N-1; k++) cout << A.at(k) << " ";
    cout << A.at(N-1) << endl;
  }
}