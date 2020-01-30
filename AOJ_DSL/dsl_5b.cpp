// DSL 5_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// いもす法 (2 次元)
int main() {
  int N; cin >> N;
  vector<vector<int>> S(1001, vector<int>(1001));
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    S.at(y1).at(x1)++;  // 左上
    S.at(y1).at(x2)--;  // 左下
    S.at(y2).at(x1)--;  // 右上
    S.at(y2).at(x2)++;  // 右下
  }
  // 横方向で累積和
  for (int y = 0; y <= 1000; y++) {
    for (int x = 1; x <= 1000; x++) S.at(y).at(x) += S.at(y).at(x-1);
  }
  // 縦方向で累積和
  for (int x = 0; x <= 1000; x++) {
    for (int y = 1; y <= 1000; y++) S.at(y).at(x) += S.at(y-1).at(x);
  }
  int ans = 0;
  for (int y = 0; y <= 1000; y++) {
    for (int x = 0; x <= 1000; x++) ans = max(ans, S.at(y).at(x));
  }
  cout << ans << endl;
}