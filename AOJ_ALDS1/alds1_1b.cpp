// ALDS1 1_B
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  long long x, y;
  cin >> x >> y;
  cout << gcd(x, y) << endl;
}