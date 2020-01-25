// DPL 1_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> C(M);
  for (int i = 0; i < M; i++) cin >> C.at(i);
  const int INF = 1000000000;
  vector<int> dp(N+1, INF);
  dp.at(0) = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int c = C.at(j);
      if (i + c <= N) {
        dp.at(i+c) = min(dp.at(i+c), dp.at(i) + 1);
      }
    }
  }
  cout << dp.at(N) << endl;
}