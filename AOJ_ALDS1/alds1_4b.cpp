// ALDS1 4_B
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> S(N);
  for (int i = 0; i < N; i++) cin >> S.at(i);
  int Q; cin >> Q;
  vector<int> T(N);
  for (int i = 0; i < Q; i++) cin >> T.at(i);

  int ans = 0;
  for (int i = 0; i < Q; i++) {
    int key = T.at(i);
    int left = 0, right = N;
    while (left < right) {
      int mid = (left + right) / 2;
      if (S.at(mid) == key) { ans++; break; }
      else if (key < S.at(mid)) right = mid;
      else left = mid + 1;
    }
  }
  cout << ans << endl;
}