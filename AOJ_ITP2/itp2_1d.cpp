// ITP2 1_D
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q; cin >> N >> Q;
  vector<vector<int> > A(N);
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int t, x; cin >> t >> x;
      A.at(t).push_back(x);
    }
    if (q == 1) {
      int t; cin >> t;
      for (int i = 0; i < A.at(t).size(); i++) {
        if (i) cout << " ";
        cout << A.at(t).at(i);
      }
      cout << endl;
    }
    if (q == 2) {
      int t; cin >> t;
      A.at(t).clear();
    }
  }
}