// NTL 1_C
// C++
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  long long g = gcd(a, b);
  return a / g * b;
}

int main() {
  int N; cin >> N;
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << endl;
}