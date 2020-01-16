// ITP2 1_A
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int x; cin >> x;
      A.push_back(x);
    }
    if (q == 1) {
      int p; cin >> p;
      cout << A.at(p) << endl;
    }
    if (q == 2) {
      A.pop_back();
    }
  }
}