// GRL 3_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 橋 : 取り除くと連結成分が増える辺
int V;
const int MAX = 100000;
vector<vector<int>> G(MAX);
vector<bool> visited(MAX);
vector<int> prenum(MAX), parent(MAX), lowest(MAX);
vector<pair<int, int>> ans;
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
      // DFS 木の辺 uv が橋 <=> prenum[u] < lowest[v]
      if (prenum.at(current) < lowest.at(nx)) {
        ans.push_back(make_pair(current, nx));
      }
    }
    else if (nx != prev) {  // このとき、current -> nx は back-edge
      lowest.at(current) = min(lowest.at(current), prenum.at(nx));
    }
  }
}

void bridges() {
  for (int i = 0; i < V; i++) {
    if (!visited.at(i)) dfs(i, -1);
  }
  for (auto &br : ans) {
    if (br.first > br.second) swap(br.first, br.second);
  }
  sort(ans.begin(), ans.end());
  for (auto br : ans) cout << br.first << " " << br.second << endl;
}

int main() {
  int E; cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    G.at(s).push_back(t);
    G.at(t).push_back(s);
  }
  bridges();
}