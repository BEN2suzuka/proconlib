// NTL 1_A
// C++14
#include <bits/stdc++.h>
using namespace std;

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
  int N; cin >> N;
  vector<pair<long long, long long>> pf = prime_factorize(N);
  cout << N << ":";
  for (auto p : pf) {
    for (int i = 0; i < p.second; i++) cout << " " << p.first;
  }
  cout << endl;
}