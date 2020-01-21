// ALDS1 14_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  string T, P; cin >> T >> P;
  int TL = T.size();
  int PL = P.size();
  for (int i = 0; i < TL; i++) {
    if (T.substr(i, PL) == P) cout << i << endl;
  }
}