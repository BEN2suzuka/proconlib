// ALDS1 11_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 有向グラフの隣接リスト表現 -> 隣接行列表現
int main() {
  int N; cin >> N;
  vector<vector<int>> M(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    int u, k; cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v; cin >> v;
      v--;
      M.at(u).at(v) = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j) cout << " ";
      cout << M.at(i).at(j);
    }
    cout << endl;
  }
}