// ALDS1 4_A
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> S(N+1);  // 番兵の席を用意
  for (int i = 0; i < N; i++) cin >> S.at(i);
  int Q; cin >> Q;
  vector<int> T(Q);
  for (int i = 0; i < Q; i++) cin >> T.at(i);

  int ans = 0;
  for (int i = 0; i < Q; i++) {
    int key = T.at(i);
    S.at(N) = key;  // 番兵
    int j = 0;
    while (S.at(j) != key) j++;
    if (j != N) ans++;
  }
  cout << ans << endl;
}