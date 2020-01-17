// ITP2 10_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b; cin >> a >> b;
  bitset<32> A(a), B(b);
  cout << (A & B) << endl;  // AND
  cout << (A | B) << endl;  // OR
  cout << (A ^ B) << endl;  // XOR
}