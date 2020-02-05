// DPL 3_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// ヒストグラムの中の最大長方形
int main() {
  int N; cin >> N;
  vector<int> H(N+1);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  stack<pair<long long, int>> S;
  // first: 高さ, second: その高さの長方形の左端の index
  long long ans = 0;
  // ヒストグラムを左から順にみていく
  for (int i = 0; i <= N; i++) {
    pair<long long, int> p(H.at(i), i);
    if (S.empty()) S.push(p);
    else {
      if (S.top().first < p.first) S.push(p);
      else if (S.top().first > p.first) {
        int left = i;
        while (!S.empty() && S.top().first >= p.first) {
          pair<long long, int> prev = S.top();
          S.pop();
          long long area = prev.first * (i - prev.second);
          ans = max(ans, area);
          left = prev.second;
        }
        p.second = left;
        S.push(p);
      }
    }
  }
  cout << ans << endl;
}