// GRL 5_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 木の直径 : 木の最遠頂点間の距離
vector<vector<pair<int, int>>> G;
vector<int> dist;  // ある頂点からの距離
pair<int, int> fur(0, 0);  // first: ある頂点から最も遠い頂点, second: その距離

void dfs(int current, int parent) {
  for (auto nx : G.at(current)) {
    if (nx.first == parent) continue;
    dist.at(nx.first) = dist.at(current) + nx.second;
    if (dist.at(nx.first) > fur.second) {
      fur.first = nx.first;
      fur.second = dist.at(nx.first);
    }
    dfs(nx.first, current);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  dist.resize(N);
  for (int i = 0; i < N-1; i++) {
    int s, t, w; cin >> s >> t >> w;
    G.at(s).push_back(make_pair(t, w));
    G.at(t).push_back(make_pair(s, w));
  }
  dfs(0, -1);  // 適当な頂点から DFS
  dist.assign(N, 0);
  dfs(fur.first, -1);  // 最も遠かった頂点 (= 木の直径の端点) から DFS
  cout << fur.second << endl;
}