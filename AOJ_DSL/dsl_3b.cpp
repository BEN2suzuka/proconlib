// DSL 3_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int ans = N+1;
  int right = 0;
  vector<int> cnt(K+1);
  int num = 0;
  for (int left = 0; left < N; left++) {
    // [left, right) で [1, K] が全て揃う最小の right を求める
    while (right < N && num < K) {
      if (A.at(right) <= K) {
        cnt.at(A.at(right))++;
        if (cnt.at(A.at(right)) == 1) num++;
      }
      right++;
    }
    if (num < K) break;  // left を進めてもダメ
    ans = min(ans, right - left);
    // left を次に進める準備
    if (left == right) right++;
    else {
      if (A.at(left) <= K) {
        cnt.at(A.at(left))--;
        if (cnt.at(A.at(left)) == 0) num--;
      }
    }
  }
  if (ans < N+1) cout << ans << endl;
  else cout << 0 << endl;
}