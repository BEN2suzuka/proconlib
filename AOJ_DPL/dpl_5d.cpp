// DPL 5_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別しない
// 箱 (K 個) : 区別する
// 入れ方に制限なし -> {N+K-1}_C_{N} (N 個の丸と K-1 個の仕切り)
int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX_C = 2000;
  // パスカルの三角形
  vector<vector<long long>> Com(MAX_C, vector<long long>(MAX_C));
  Com.at(0).at(0) = 1;
  for (int i = 1; i < MAX_C; i++) {
    Com.at(i).at(0) = 1;
    for (int j = 1; j <= i; j++) {
      Com.at(i).at(j) = (Com.at(i-1).at(j-1) + Com.at(i-1).at(j)) % MOD;
    }
  }
  cout << Com.at(N+K-1).at(N) << endl;
}