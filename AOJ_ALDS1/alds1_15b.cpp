// ALDS1 15_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 有理ナップサック問題
int main() {
  int N; cin >> N;
  double W; cin >> W;
  vector<pair<double, double>> A;  // first : 単位重さあたりの価値, second : 重さ
  for (int i = 0; i < N; i++) {
    double v, w; cin >> v >> w;
    A.push_back(make_pair(v/w, w));
  }
  sort(A.begin(), A.end(), greater<pair<double, double>>());
  double ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A.at(i).first * min(A.at(i).second, W);
    W -= min(A.at(i).second, W);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}