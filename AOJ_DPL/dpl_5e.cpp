// DPL 5_E
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別しない
// 箱 (K 個) : 区別する
// 箱の中身は 1 つ以下 -> {K}_C_{N} (ボールを入れる箱を N 個選ぶ)
int main() {
  int N, K; cin >> N >> K;
  const int MOD = 1000000007;
  const int MAX_C = 1001;
  // パスカルの三角形
  vector<vector<long long>> Com(MAX_C, vector<long long>(MAX_C));
  Com.at(0).at(0) = 1;
  for (int i = 1; i < MAX_C; i++) {
    Com.at(i).at(0) = 1;
    for (int j = 1; j <= i; j++) {
      Com.at(i).at(j) = (Com.at(i-1).at(j-1) + Com.at(i-1).at(j)) % MOD;
    }
  }
  cout << Com.at(K).at(N) << endl;
}