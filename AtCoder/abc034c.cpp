// ABC 034 C
// C++14
#include <bits/stdc++.h>
using namespace std;

// フェルマーの小定理を利用して逆元を計算
// a が素数 p で割り切れないとき、a の逆元は a^{p-2} mod p

// 階乗、階乗の逆元のメモ
vector<long long> fac, fac_inv;

// a^b mod p を返す (繰り返し自乗法)
long long modpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long res = modpow(a, b / 2, p);
  if (b % 2 == 0) res = (res * res) % p;
  else res = (((res * res) % p) * a) % p;
  return res;
}

// mod p における a の逆元 a^{p-2} mod p を返す
long long inverse(long long a, long long p) {
  return modpow(a, p-2, p);
}

// nCk (mod p) の前処理 O(n log p)
void comInit(int n, int p) {
  fac.resize(n+1);
  fac_inv.resize(n+1);
  fac.at(0) = fac.at(1) = 1;
  fac_inv.at(0) = fac_inv.at(1) = 1;
  for (int i = 2; i <= n; i++) {
    fac.at(i) = fac.at(i-1) * i % p;
    fac_inv.at(i) = fac_inv.at(i-1) * inverse(i, p) % p;
  }
}

// nCk mod p を返す O(1)
long long com(int n, int k, int p) {
  if (n < k || n < 0 || k < 0) return 0;
  return fac.at(n) * (fac_inv.at(k) * fac_inv.at(n-k) % p) % p;
}

int main() {
  const int MOD = 1000000007;
  int W, H; cin >> W >> H;
  comInit(W+H, MOD);  // 前処理
  cout << com(W+H-2, W-1, MOD) << endl;  // W+H-2_C_W-1 (mod MOD)
}