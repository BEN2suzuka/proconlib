// DPL 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// ボール (N 個) : 区別する
// 箱 (K 個) : 区別する
// 箱の中身は 1 つ以上 -> {K}_Σ_{i=0} (-1)^i {K}_C_{i} (K-i)^N
//
// K 個の箱から、空にする i 個の箱を選ぶ {K}_C_{i}
// 他の箱 K-i 個に N 個のボールを自由に入れる (K-i)^N
//
// ex. 箱が 3 個 (A, B, C)
// 「少なくとも 1 つ以上の箱が空」
// = n(A が空) + n(B が空) + n(C が空)
// - n(A と B が空) - n(A と C が空) - n(B と C が空)
// + n(A と B と C が空)
// よって、「箱の中身が 1 つ以上」は
// (全体 K^N) - (空が 1 つ) + (空が 2 つ) - (空が 3 つ)

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;  // 余りが負のとき、わる数を足す
  return res;
}

long long modpow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long res = modpow(a, b / 2, mod);
  if (b % 2 == 0) res = (res * res) % mod;
  else res = (((res * res) % mod) * a) % mod;
  return res;
}

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
  
  long long ans = 0;
  // {K}_Σ_{i=0} (-1)^i {K}_C_{i} (K-i)^N
  // i = 0 は「全体」
  for (int i = 0; i <= K; i++) {
    long long tmp = modpow(K - i, N, MOD);
    tmp = tmp * Com.at(K).at(i) % MOD;
    if (i % 2 == 1) tmp = mod(tmp * (-1), MOD);
    ans = (ans + tmp) % MOD;
  }
  cout << ans << endl;
}