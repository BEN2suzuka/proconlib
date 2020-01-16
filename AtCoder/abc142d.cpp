// ABC 142 D
// C++14
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long n) {
  vector<pair<long long, long long>> res;
  for (long long p = 2; p*p <= n; p++) {
    if (n % p != 0) continue;
    int num = 0;
    while (n % p == 0) { num++; n /= p; }
    res.push_back(make_pair(p, num));
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}

int main() {
  long long A, B; cin >> A >> B;
  long long x = gcd(A, B);
  vector<pair<long long, long long>> pf = prime_factorize(x);
  cout << pf.size() + 1 << endl;
}