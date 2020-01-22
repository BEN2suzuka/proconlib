// ALDS1 3_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  stack<int> S1;  // \ の x 座標
  stack<pair<int, int>> S2;  // first : 水たまりの左端の x 座標, second : 面積
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == '\\') S1.push(i);
    if (s.at(i) == '/' && S1.size() > 0) {
      int j = S1.top();  // 今の / に対応する \ の位置
      S1.pop();
      int a = i - j;  // 面積
      // 別の水たまりとつながる
      while (S2.size() > 0 && j < S2.top().first) {
        a += S2.top().second;
        S2.pop();
      }
      S2.push(make_pair(j, a));
    }
  }

  int A = 0;
  vector<int> ans;
  while (S2.size() > 0) {
    A += S2.top().second;
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << A << endl;
  cout << ans.size();
  for (int v : ans) {
    cout << " " << v;
  }
  cout << endl;
}