// ALDS1 1_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> R(N);
  for (int i = 0; i < N; i++) cin >> R.at(i);
  int ans = -1000000007;
  int tmp = R.at(0);
  for (int i = 1; i < N; i++) {
    ans = max(ans, R.at(i) - tmp);
    tmp = min(tmp, R.at(i));  // ここまでの価格の最小値
  }
  cout << ans << endl;
}
