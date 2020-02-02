// GRL 5_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// ある頂点を根とした木の高さ : その頂点から最も遠い葉までの距離
vector<vector<pair<int, int>>> G;
pair<int, int> fur(0, 0);  // first: ある頂点から最も遠い頂点, second: その距離

void dfs(int current, int parent, vector<int> &vec) {
  for (auto nx : G.at(current)) {
    if (nx.first == parent) continue;
    vec.at(nx.first) = vec.at(current) + nx.second;
    if (vec.at(nx.first) > fur.second) {
      fur.first = nx.first;
      fur.second = vec.at(nx.first);
    }
    dfs(nx.first, current, vec);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  for (int i = 0; i < N-1; i++) {
    int s, t, w; cin >> s >> t >> w;
    G.at(s).push_back(make_pair(t, w));
    G.at(t).push_back(make_pair(s, w));
  }
  vector<int> tmp(N), ans1(N), ans2(N);
  dfs(0, -1, tmp);  // 適当な頂点から DFS (木の直径の端点の一方を求める)
  fur.second = 0;
  dfs(fur.first, -1, ans1);  // 最も遠かった頂点 (= 木の直径の端点) から DFS
  fur.second = 0;
  dfs(fur.first, -1, ans2);  // 木の直径の端点のもう一方から DFS
  for (int i = 0; i < N; i++) cout << max(ans1.at(i), ans2.at(i)) << endl;
}