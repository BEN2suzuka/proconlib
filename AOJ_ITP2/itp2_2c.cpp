// ITP2 2_C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q; 
  vector<priority_queue<int> > Q(n);
  for (int i = 0; i < q; i++) {
    int query; cin >> query;
    if (query == 0) {
      int t, x; cin >> t >> x;
      Q.at(t).push(x);
    }
    if (query == 1) {
      int t; cin >> t;
      if (!Q.at(t).empty()) cout << Q.at(t).top() << endl;
    }
    if (query == 2) {
      int t; cin >> t;
      if (!Q.at(t).empty()) Q.at(t).pop();
    }
  }
}