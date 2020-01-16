// ITP2 4_A
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int b, e; cin >> b >> e;
    reverse(A.begin() + b, A.begin() + e);
  }
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}