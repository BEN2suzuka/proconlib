// ITP2 10_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x; cin >> x;
  bitset<32> b(x);
  cout << b << endl;
  cout << ~b << endl;  // 反転
  cout << (b << 1) << endl;  // 左へ論理シフト
  cout << (b >> 1) << endl;  // 右へ論理シフト
}