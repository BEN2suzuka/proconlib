// ALDS1 13_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int N = 8;
// col, dpos, dneg で襲撃チェック
vector<int> row(N, -1), col(N, -1), dpos(2*N-1, -1), dneg(2*N-1, -1);
vector<vector<bool>> G(N, vector<bool>(N));

int func(int y) {
  if (y == N) {
    // 配置チェック
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (G.at(y).at(x)) {
          if (row.at(y) != x) return 0;  // NG
        }
      }
    }
    return 1;  // OK
  }
  for (int x = 0; x < N; x++) {
    // (x, y) は襲撃されている
    if (col.at(x) == 1 || dpos.at(y+x) == 1 || dneg.at(y-x+N-1) == 1) continue;
    // (x, y) にクイーンを配置
    row.at(y) = x;
    col.at(x) = 1;
    dpos.at(y+x) = 1;
    dneg.at(y-x+N-1) = 1;
    if (func(y+1)) return 1;  // 配置成功
    // (x, y) に配置されているクイーンを取り除く
    row.at(y) = -1;
    col.at(x) = -1;
    dpos.at(y+x) = -1;
    dneg.at(y-x+N-1) = -1;
  }
  return 0;  // 配置失敗
}

int main() {
  int k; cin >> k;
  for (int i = 0; i < k; i++) {
    int r, c; cin >> r >> c;
    G.at(r).at(c) = true;
  }
  func(0);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (row.at(y) == x) cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
}