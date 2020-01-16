// ITP2 4_B
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int b, m, e; cin >> b >> m >> e;
    rotate(A.begin() + b, A.begin() + m, A.begin() + e);
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}