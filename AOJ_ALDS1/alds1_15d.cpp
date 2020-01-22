// ALDS1 15_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  vector<int> cnt(26);
  for (char c : S) cnt.at(c - 'a')++;

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < 26; i++) {
    if (cnt.at(i)) pq.push(cnt.at(i));
  }
  if (pq.size() == 1) {
    cout << S.size() << endl;
    return 0;
  }
  int ans = 0;
  while (pq.size() > 1) {
    int p = pq.top(); pq.pop();
    int q = pq.top(); pq.pop();
    ans += p + q;
    pq.push(p + q);
  }
  cout << ans << endl;
}