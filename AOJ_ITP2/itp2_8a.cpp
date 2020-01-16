// ITP2 8_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> M;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q;
    string key;
    cin >> q >> key;
    if (q == 0) {
      int x; cin >> x;
      M[key] = x;
    }
    else {
      cout << M.at(key) << endl;
    }
  }
}