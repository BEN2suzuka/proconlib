// DPL 4_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 半分全列挙
int main() {
  int N, K; cin >> N >> K;
  long long L, R; cin >> L >> R;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  // S[i] := i 枚選んだときの合計金額の集合
  vector<vector<long long>> S1(N+1), S2(N+1);
  int N2 = N / 2;
  // 前半 N2 枚について、選ぶかどうかを全列挙 (2^N)
  for (int i = 0; i < (1 << N2); i++) {
    long long value = 0;
    int cnt = 0;
    for (int j = 0; j < N2; j++) {
      if ((i >> j) & 1) {  // j 番目のビットが立っている
        value += A.at(j);
        cnt++;
      }
    }
    S1.at(cnt).push_back(value);
  }
  // 後半 N - N2 枚も全列挙
  for (int i = 0; i < (1 << (N - N2)); i++) {
    long long value = 0;
    int cnt = 0;
    for (int j = 0; j < N - N2; j++) {
      if ((i >> j) & 1) {
        value += A.at(N2 + j);
        cnt++;
      }
    }
    S2.at(cnt).push_back(value);
  }
  // 後半 N - N2 枚についてソート
  for (int i = 0; i < N - N2 + 1; i++) sort(S2.at(i).begin(), S2.at(i).end());
  long long ans = 0;
  // 前半から i 枚選んだときの合計金額を全列挙
  for (int i = 0; i <= K; i++) {
    for (auto v : S1.at(i)) {
      // 後半から K-i 枚選ぶ
      // L-v 円以上 R-v 円以下となる選び方の総数を求める
      ans += upper_bound(S2.at(K-i).begin(), S2.at(K-i).end(), R-v) - lower_bound(S2.at(K-i).begin(), S2.at(K-i).end(), L-v);
    }
  }
  cout << ans << endl;
}