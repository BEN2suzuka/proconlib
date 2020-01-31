// GRL 3_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 関節点 : 関節点と、その点から出る全ての辺を削除すると、グラフが非連結になる
int V;
const int MAX = 100000;
vector<vector<int>> G(MAX);
vector<bool> visited(MAX);
vector<int> prenum(MAX), parent(MAX), lowest(MAX);
int timer = 1;

void dfs(int current, int prev) {
  prenum.at(current) = lowest.at(current) = timer;
  timer++;
  visited.at(current) = true;
  for (int nx : G.at(current)) {
    if (!visited.at(nx)) {
      parent.at(nx) = current;
      dfs(nx, current);  // 子の処理
      // 子の lowest をチェック
      lowest.at(current) = min(lowest.at(current), lowest.at(nx));
    }
    else if (nx != prev) {  // このとき、current -> nx は back-edge
      lowest.at(current) = min(lowest.at(current), prenum.at(nx));
    }
  }
}

void art_points() {
  dfs(0, -1);
  set<int> ap;
  int cnt = 0;
  for (int i = 1; i < V; i++) {
    int p = parent.at(i);
    if (p == 0) cnt++;
    else if (prenum.at(p) <= lowest.at(i)) ap.insert(p);
    // prenum[parent[u]] <= lowest[u] <=> parent[u] は関節点
  }
  if (cnt > 1) ap.insert(0);  // root が子を 2 つ以上もつ <=> root は関節点
  for (auto it = ap.begin(); it != ap.end(); it++) cout << *it << endl;
}

int main() {
  int E; cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    G.at(s).push_back(t);
    G.at(t).push_back(s);
  }
  art_points();
}