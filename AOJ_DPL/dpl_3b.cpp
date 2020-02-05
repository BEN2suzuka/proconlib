// DPL 3_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最大長方形
int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> G(H, vector<int>(W+1));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cin >> G.at(i).at(j);
  }
  vector<vector<int>> T(H, vector<int>(W+1));
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (G.at(i).at(j) == 1) T.at(i).at(j) = 0;
      else {
        if (i == 0) T.at(i).at(j) = 1;
        else T.at(i).at(j) = T.at(i-1).at(j) + 1;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < H; i++) {
    // first: 高さ, second: その高さの長方形の左端の index
    stack<pair<long long, int>> S;
    // ヒストグラムを左から順にみていく
    for (int j = 0; j <= W; j++) {
      pair<long long, int> p(T.at(i).at(j), j);
      if (S.empty()) S.push(p);
      else {
        if (S.top().first < p.first) S.push(p);
        else if (S.top().first > p.first) {
          int left = j;
          while (!S.empty() && S.top().first >= p.first) {
            pair<long long, int> prev = S.top();
            S.pop();
            long long area = prev.first * (j - prev.second);
            ans = max(ans, area);
            left = prev.second;
          }
          p.second = left;
          S.push(p);
        }
      }
    }
  }
  cout << ans << endl;
}