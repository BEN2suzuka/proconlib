// ALDS1 11_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int N;
int t = 0;  // 時刻
vector<vector<int>> M;
vector<int> C;  // 0 : 未訪問, 1 : 訪問中, 2 : 訪問完了
vector<int> d;  // v を最初に訪問した時刻
vector<int> f;  // v の隣接リストを調べ終えた時刻

void dfs(int cur) {
  C.at(cur) = 1;
  t++;
  d.at(cur) = t;
  for (int nx : M.at(cur)) {
    if (C.at(nx) == 0) dfs(nx);
  }
  C.at(cur) = 2;
  t++;
  f.at(cur) = t;
}

int main() {
  cin >> N;
  M.resize(N);  // 隣接リスト表現
  C.resize(N);
  d.resize(N);
  f.resize(N);
  for (int i = 0; i < N; i++) {
    int u, k; cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v; cin >> v;
      v--;
      M.at(u).push_back(v);  // 有向グラフ
    }
  }

  for (int i = 0; i < N; i++) {
    if (C.at(i) == 0) dfs(i);
  }
  for (int i = 0; i < N; i++) {
    cout << i+1 << " " << d.at(i) << " " << f.at(i) << endl;
  }
}