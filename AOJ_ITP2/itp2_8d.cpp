// ITP2 8_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  multimap<string, int> M;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      string key; cin >> key;
      int x; cin >> x;
      M.insert(make_pair(key, x));
    }
    if (q == 1) {
      string key; cin >> key;
      auto l = M.lower_bound(key);
      auto r = M.upper_bound(key);
      for (auto iter = l; iter != r; iter++) {
        cout << (*iter).second << endl;
        // cout << iter->second << endl;
      }
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