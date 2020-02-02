// DPL 5_F
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別しない
// 箱 (K 個) : 区別する
// 箱の中身は 1 つ以上 -> {N-1}_C_{K-1} (N-K 個の丸と K-1 個の仕切り)
int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX_C = 1000;
  // パスカルの三角形
  vector<vector<long long>> Com(MAX_C, vector<long long>(MAX_C));
  Com.at(0).at(0) = 1;
  for (int i = 1; i < MAX_C; i++) {
    Com.at(i).at(0) = 1;
    for (int j = 1; j <= i; j++) {
      Com.at(i).at(j) = (Com.at(i-1).at(j-1) + Com.at(i-1).at(j)) % MOD;
    }
  }
  cout << Com.at(N-1).at(K-1) << endl;
}