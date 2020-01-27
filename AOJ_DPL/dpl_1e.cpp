// DPL_1_E
// C++14
#include <bits/stdc++.h>
using namespace std;

// 編集距離 (レーベンシュタイン距離)
int main() {
  string S, T; cin >> S >> T;
  const int INF = 1000000007;
  vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1, INF));
  for (int i = 0; i <= S.size(); i++) dp.at(i).at(0) = i;
  for (int j = 0; j <= T.size(); j++) dp.at(0).at(j) = j;

  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < T.size(); j++) {
      int x;
      if (S.at(i) == T.at(j)) x = 0;
      else x = 1;
      // 置換 or 何もしない
      dp.at(i+1).at(j+1) = min(dp.at(i+1).at(j+1), dp.at(i).at(j) + x);
      // 削除
      dp.at(i+1).at(j+1) = min(dp.at(i+1).at(j+1), dp.at(i).at(j+1) + 1);
      // 挿入
      dp.at(i+1).at(j+1) = min(dp.at(i+1).at(j+1), dp.at(i+1).at(j) + 1);
    }
  }
  cout << dp.at(S.size()).at(T.size()) << endl;
}