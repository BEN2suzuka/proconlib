// GRL 1_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// ワーシャル・フロイド
// 負の閉路がない限り、負の重みを持つ辺が存在しても問題ない
int V;
const long long INF = 1LL << 60;
vector<vector<long long>> M;

void floyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      if (M.at(i).at(k) == INF) continue;
      for (int j = 0; j < V; j++) {
        if (M.at(k).at(j) == INF) continue;
        M.at(i).at(j) = min(M.at(i).at(j), M.at(i).at(k) + M.at(k).at(j));
      }
    }
  }
}

int main() {
  int E;
  cin >> V >> E;
  M = vector<vector<long long>>(V, vector<long long>(V, INF));
  for (int i = 0; i < V; i++) M.at(i).at(i) = 0;
  for (int i = 0; i < E; i++) {
    int s, t, d; cin >> s >> t >> d;
    M.at(s).at(t) = d;
  }
  floyd();
  bool negative = false;
  for (int i = 0; i < V; i++) {
    if (M.at(i).at(i) < 0) negative = true;
  }
  if (negative) cout << "NEGATIVE CYCLE" << endl;
  else {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (j) cout << " ";
        if (M.at(i).at(j) == INF) cout << "INF";
        else cout << M.at(i).at(j);
      }
      cout << endl;
    }
  }
}