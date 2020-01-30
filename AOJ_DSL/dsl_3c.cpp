// DSL 3_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<long long> query(N);
  for (int i = 0; i < Q; i++) cin >> query.at(i);
  for (int i = 0; i < Q; i++) {
    long long x = query.at(i);
    long long ans = 0;
    int right = 0;
    long long sum = 0;
    for (int left = 0; left < N; left++) {
      // sum に A.at(right) を加えても大丈夫ならば right を動かす
      while (right < N && sum + A.at(right) <= x) {
        sum += A.at(right);
        right++;
      }
      ans += (right - left);
      // left を次に進める準備
      if (left == right) right++;
      else sum -= A.at(left);
    }
    cout << ans << endl;
  }
}