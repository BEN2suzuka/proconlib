// DPL 1_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W; cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++) cin >> v.at(i) >> w.at(i);
  vector<vector<int>> dp(N+1, vector<int>(W+1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));
      if (j + w.at(i) <= W) {
        dp.at(i+1).at(j + w.at(i)) = max(dp.at(i+1).at(j + w.at(i)), dp.at(i+1).at(j) + v.at(i));
      }
    }
  }
  cout << dp.at(N).at(W) << endl;
}