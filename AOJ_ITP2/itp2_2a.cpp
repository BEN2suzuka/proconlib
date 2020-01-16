// ITP2 2_A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q; cin >> N >> Q;
  vector<stack<int> > S(N);
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int t, x; cin >> t >> x;
      S.at(t).push(x);
    }
    if (q == 1) {
      int t; cin >> t;
      if (!S.at(t).empty()) cout << S.at(t).top() << endl;
    }
    if (q == 2) {
      int t; cin >> t;
      if (!S.at(t).empty()) S.at(t).pop();
    }
  }
}