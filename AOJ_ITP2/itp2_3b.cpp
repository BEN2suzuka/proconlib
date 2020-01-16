// ITP2 3_B
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int com, b, e; cin >> com >> b >> e;
    if (com == 0) {
      int ans = 1000000001;
      for (int j = b; j < e; j++) {
        ans = min(ans, A.at(j));
      }
      cout << ans << endl;
    }
    if (com == 1) {
      int ans = -1000000001;
      for (int j = b; j < e; j++) {
        ans = max(ans, A.at(j));
      }
      cout << ans << endl;
    }
  }
}