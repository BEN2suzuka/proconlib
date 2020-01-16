// ITP2 1_C
#include <bits/stdc++.h>
using namespace std;

int main() {
  list<int> L;
  list<int>::iterator cur = L.end();
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int x; cin >> x;
      cur = L.insert(cur, x);
    }
    if (q == 1) {
      int d; cin >> d;
      if (d > 0) {
        for (int i = 0; i < d; i++) cur++;
      }
      else {
        for (int i = 0; i < -d; i++) cur--;
      }
    }
    if (q == 2) {
      cur = L.erase(cur);
    }
  }
  for (list<int>::iterator i = L.begin(); i != L.end(); i++) {
    cout << *i << endl;
  }
}