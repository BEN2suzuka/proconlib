// NTL 1_B
// C++14
#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  long long res = modpow(a, b / 2, mod);
  if (b % 2 == 0) res = (res * res) % mod;
  else res = (((res * res) % mod) * a) % mod;
  return res;
}

int main() {
  int M, N; cin >> M >> N;
  int MOD = 1000000007;
  cout << modpow(M, N, MOD) << endl;
}