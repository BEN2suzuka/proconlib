// ITP2 7_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> S;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q, x; cin >> q >> x;
    if (q == 0) {
      S.insert(x);
      cout << S.size() << endl;
    }
    if (q == 1) {
      if (S.count(x)) cout << 1 << endl;
      else cout << 0 << endl;
    }
    if (q == 2) {
      S.erase(x);
    }
  }
}