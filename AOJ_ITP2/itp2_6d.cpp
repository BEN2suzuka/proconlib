// ITP2 6_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int k; cin >> k;
    int l = lower_bound(A.begin(), A.end(), k) - A.begin();
    int r = upper_bound(A.begin(), A.end(), k) - A.begin();
    cout << l << " " << r << endl;
  }
}