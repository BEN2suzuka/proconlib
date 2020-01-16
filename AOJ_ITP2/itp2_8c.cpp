// ITP2 8_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> M;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      string key; cin >> key;
      int x; cin >> x;
      M[key] = x;
    }
    if (q == 1) {
      string key; cin >> key;
      if (M.count(key)) cout << M.at(key) << endl;
      else cout << 0 << endl;
    }
    if (q == 2) {
      string key; cin >> key;
      M.erase(key);
    }
    if (q == 3) {
      string L, R; cin >> L >> R;
      auto l = M.lower_bound(L);
      auto r = M.upper_bound(R);
      for (auto iter = l; iter != r; iter++) {
        cout << (*iter).first << " " << (*iter).second << endl;
        // cout << iter->first << " " << iter->second << endl;
      }
    }
  }
}