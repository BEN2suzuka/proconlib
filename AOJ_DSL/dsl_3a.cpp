// DSL 3_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// しゃくとり法
int main() {
  int N, S; cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int ans = N+1;
  int right = 0;
  long long sum = 0;
  for (int left = 0; left < N; left++) {
    // [left, right) の総和が S 以上となる最小の right を求める
    while (right < N && sum < S) {
      sum += A.at(right);
      right++;
    }
    if (sum < S) break;  // left を進めてもダメ
    ans = min(ans, right - left);
    // left を次に進める準備
    if (left == right) right++;
    else sum -= A.at(left);  // left がインクリメントされるので A.at(left) を引く
  }
  if (ans < N+1) cout << ans << endl;
  else cout << 0 << endl;
}