// ALDS1 15_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 区間スケジューリング問題
// 活動 i に参加するかどうかは、時刻 t[i] 以降に影響しない
int main() {
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int s, t; cin >> s >> t;
    A.at(i) = make_pair(t, s);  // 終了時刻の早い順に並べる
  }
  sort(A.begin(), A.end());
  int ans = 0;
  int tmp = -1;  // 最後に選んだ活動の終了時刻
  for (int i = 0; i < N; i++) {
    if (tmp < A.at(i).second) {
      ans++;
      tmp = A.at(i).first;
    }
  }
  cout << ans << endl;
}