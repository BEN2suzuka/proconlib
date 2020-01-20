// ALDS1 11_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> M;
vector<int> d;  // 距離

void bfs(int s) {
  queue<int> tovist;
  tovist.push(s);
  d.at(s) = 0;
  while (!tovist.empty()) {
    int cur = tovist.front();
    tovist.pop();
    for (int nx : M.at(cur)) {
      if (d.at(nx) != -1) continue;  // 訪問済み
      d.at(nx) = d.at(cur) + 1;
      tovist.push(nx);
    }
  }
}

int main() {
  cin >> N;
  M.resize(N);
  d.assign(N, -1);
  for (int i = 0; i < N; i++) {
    int u, k; cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v; cin >> v;
      v--;
      M.at(u).push_back(v);
    }
  }
  
  bfs(0);
  for (int i = 0; i < N; i++) {
    cout << i+1 << " " << d.at(i) << endl;
  }
}