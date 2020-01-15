// ALDS1 1_C
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long p = 2; p*p <= n; p++) {
    if (n % p == 0) return false;
  }
  return true;
}

int main() {
  int N; cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (isPrime(x)) ans++;
  }
  cout << ans << endl;
}