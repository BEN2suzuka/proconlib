// DSL 5_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// いもす法
int main() {
  int N, T; cin >> N >> T;
  vector<int> L(N), R(N), S(T+1);
  for (int i = 0; i < N; i++) cin >> L.at(i) >> R.at(i);
  for (int i = 0; i < N; i++) {
    S.at(L.at(i))++;  // 入店
    S.at(R.at(i))--;  // 出店
  }
  for (int i = 0; i < T; i++) S.at(i+1) += S.at(i);
  int ans = 0;
  for (int i = 0; i <= T; i++) ans = max(ans, S.at(i));
  cout << ans << endl;
}