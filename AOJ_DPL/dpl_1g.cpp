// DPL 1_G
// C++14
#include <bits/stdc++.h>
using namespace std;

// 個数制限付きナップサック問題
int main() {
  int N, W; cin >> N >> W;
  vector<int> v, w, m;
  // 価値 v、重さ w の品物 m 個 を分解する
  // 価値 v、重さ w の品物 1 個
  // 価値 2v、重さ 2w の品物 1 個
  // 価値 4v、重さ 4w の品物 1 個
  //  :
  // 価値 2^k*v、重さ 2^k*w の品物 1 個
  // 価値 av、重さ aw の品物 1 個 (0 <= a < 2^{k+1})
  // に分解して、0-1 ナップサック問題に帰着
  for (int i = 0; i < N; i++) {
    int vi, wi, m; cin >> vi >> wi >> m;
    int cnt = 1;
    while (cnt <= m) {
      v.push_back(vi * cnt);
      w.push_back(wi * cnt);
      m -= cnt;
      cnt *= 2;
    }
    if (m > 0) {
      v.push_back(vi * m);
      w.push_back(wi * m);
    }
  }
  int M = v.size();
  vector<vector<int>> dp(M+1, vector<int>(W+1));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j <= W; j++) {
      dp.at(i+1).at(j) = max(dp.at(i+1).at(j), dp.at(i).at(j));
      if (j + w.at(i) <= W) {
        int nj = j + w.at(i);
        dp.at(i+1).at(nj) = max(dp.at(i+1).at(nj), dp.at(i).at(j) + v.at(i));
      }
    }
  }
  cout << dp.at(M).at(W) << endl;
}