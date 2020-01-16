// ITP2 7_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  multiset<int> S;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int x; cin >> x;
      S.insert(x);
      cout << S.size() << endl;
    }
    if (q == 1) {
      int x; cin >> x;
      cout << S.count(x) << endl;
    }
    if (q == 2) {
      int x; cin >> x;
      S.erase(x);
    }
    if (q == 3) {
      int L, R; cin >> L >> R;
      auto l = S.lower_bound(L);
      auto r = S.upper_bound(R);
      for (auto iter = l; iter != r; iter++) cout << *iter << endl;
    }
  }
}