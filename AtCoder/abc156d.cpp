// ABC 156 D
// C++14
#include <bits/stdc++.h>
using namespace std;

// nCk
// n <= 10^9 (固定)、k <= 2*10^5
// 逆元の計算にはフェルマーの小定理を利用

// com[k] := nCk の値をメモ
vector<long long> com;

// a^b mod p を返す
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

// nCk (mod p) の前処理 O(k log p)
void comInit(long long n, long long k, long long p) {
  com.resize(k+1);
  com.at(0) = 1;
  long long tmp = 1;
  for (int i = 1; i <= k; i++) {
    tmp = ((tmp * (n-i+1) % p) * inverse(i, p)) % p;
    com.at(i) = tmp;
  }
}

// val を p で割った余り (>= 0) を返す
long long mod(long long val, long long p) {
  long long res = val % p;
  if (res < 0) res += p;
  return res;
}

int main() {
  const int MOD = 1000000007;
  int n, a, b; cin >> n >> a >> b;
  comInit(n, 200000, MOD);  // 前処理
  long long ans = modpow(2, n, MOD);
  cout << mod(ans - 1 - com.at(a) - com.at(b), MOD) << endl;
}