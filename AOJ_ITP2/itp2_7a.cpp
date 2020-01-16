// ITP2 7_A
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
    else {
      if (S.count(x)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}