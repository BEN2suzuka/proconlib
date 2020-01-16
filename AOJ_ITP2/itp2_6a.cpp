// ITP2 6_A
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
    bool found = false;
    int left = 0, right = N;
    while (left < right) {
      int mid = (left + right) / 2;
      if (A.at(mid) == k) {
        found = true;
        cout << 1 << endl;
        break;
      }
      else if (k < A.at(mid)) right = mid;
      else left = mid + 1;
    }
    if (!found) cout << 0 << endl;
  }
}