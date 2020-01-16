// ITP2 2_D
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q; cin >> N >> Q; 
  vector<list<int> > L(N);
  for (int i = 0; i < Q; i++) {
    int q; cin >> q;
    if (q == 0) {
      int t, x; cin >> t >> x;
      L.at(t).push_back(x);
    }
    if (q == 1) {
      int t; cin >> t;
      list<int>::iterator iter;
      for (iter = L.at(t).begin(); iter != L.at(t).end(); iter++) {
        if (iter != L.at(t).begin()) cout << " ";
        cout << *iter;
      }
      cout << endl;
    }
    if (q == 2) {
      int s, t; cin >> s >> t;
      L.at(t).splice(L.at(t).end(), L.at(s));
    }
  }
}