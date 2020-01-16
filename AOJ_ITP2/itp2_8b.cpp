// ITP2 8_B
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
    if (q == 1) {
      if (M.count(key)) cout << M.at(key) << endl;
      else cout << 0 << endl;
    }
    if (q == 2) {
      M.erase(key);
    }
  }
}