// ABC 126 D
// C++14
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> G;
vector<int> ans;
int INF = 1000000000;

void dfs(int current, int parent, int color) {
  for (auto nx : G.at(current)) {
    if (nx.first == parent) continue;
    if (nx.second % 2 == 0) ans.at(nx.first) = color;
    else ans.at(nx.first) = (color + 1) % 2;
    dfs(nx.first, current, ans.at(nx.first));
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  ans.assign(N, INF);
  ans.at(0) = 0;
  for (int i = 0; i < N-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    G.at(u).push_back(make_pair(v, w));
    G.at(v).push_back(make_pair(u, w));
  }
  dfs(0, -1, 0);
  for (int i = 0; i < N; i++) cout << ans.at(i) << endl;
}