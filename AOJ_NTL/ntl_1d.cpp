// NTL 1_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 1 から n までの自然数のうち、n と互いに素なものの個数

// オイラーの phi 関数
long long euler_phi(long long n) {
  long long res = n;
  for (long long p = 2; p*p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      res -= res / p;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}

int main() {
  long long N; cin >> N;
  cout << euler_phi(N) << endl;
}
