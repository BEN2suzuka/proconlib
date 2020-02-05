// DPL 3_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最大正方形
// dp[i][j] := (i, j) から左上に向かってできる最大正方形の辺の長さ
// dp[i][j] は、その左上、上、左の要素のなかで最も小さい値に 1 を加えたもの
int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> G(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> G.at(i).at(j);
  }
  int L = 0;
  vector<vector<int>> dp(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (G.at(i).at(j) == 0) {
        dp.at(i).at(j) = 1;
        L = 1;
      }
    }
  }
  for (int i = 1; i < H; i++) {
    for (int j = 1; j < W; j++) {
      if (G.at(i).at(j) == 0) {
        int c1 = dp.at(i-1).at(j-1);  // 左上
        int c2 = dp.at(i-1).at(j);  // 上
        int c3 = dp.at(i).at(j-1);  // 左
        dp.at(i).at(j) = min(c1, min(c2, c3)) + 1;  // 最小値 + 1
        L = max(L, dp.at(i).at(j));
      }
    }
  }
  cout << L * L << endl;
}