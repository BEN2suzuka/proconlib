// ITP2 1_B
#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<int> A;
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int d, x; cin >> d >> x;
      if (d == 0) A.push_front(x);
      else A.push_back(x);
    }
    if (q == 1) {
      int p; cin >> p;
      cout << A.at(p) << endl;
    }
    if (q == 2) {
      int d; cin >> d;
      if (d == 0) A.pop_front();
      else A.pop_back();
    }
  }
}