// DPL 1_H
// C++14
#include <bits/stdc++.h>
using namespace std;

// 巨大ナップサック問題 (半分全列挙)
int main() {
  int N; cin >> N;
  long long W; cin >> W;
  vector<long long> v(N), w(N);
  for (int i = 0; i < N; i++) cin >> v.at(i) >> w.at(i);
  int N2 = N / 2;
  vector<pair<long long, long long>> P;  // first: sum_w, second: sum_v
  // 前半 N2 個について、選ぶかどうかで全列挙 (2^N2)
  for (int i = 0; i < (1 << N2); i++) {
    long long sum_w = 0, sum_v = 0;
    for (int j = 0; j < N2; j++) {
      if ((i >> j) & 1) {  // j 番目のビットが立っている
        sum_w += w.at(j);
        sum_v += v.at(j);
      }
    }
    P.push_back(make_pair(sum_w, sum_v));
  }
  // 無駄な要素を取り除く
  // P[i].first <= P[j].first かつ P[i].second >= P[j].second となる j は不要
  sort(P.begin(), P.end());
  int m = 1;
  for (int i = 1; i < (1 << N2); i++) {
    // P[i].first <= P[j].first <=> P[i].second < P[j].second となるようにする
    if (P.at(m-1).second < P.at(i).second) {  // この条件を満たす i を残す
      P.at(m) = P.at(i);
      m++;
    }
  }
  // 後半 N-N2 個について全列挙
  const long long INF = 1LL << 60;
  long long ans = 0;
  for (int i = 0; i < (1 << N - N2); i++) {
    long long sum_w = 0, sum_v = 0;
    for (int j = 0; j < N - N2; j++) {
      if ((i >> j) & 1) {
        sum_w += w.at(N2 + j);
        sum_v += v.at(N2 + j);
      }
    }
    // P[idx].first <= W - sum_w を満たす最大の idx を求める
    if (sum_w <= W) {
      pair<long long, long long> tmp(W - sum_w, INF);
      // 範囲は [0, m)
      // idx = (W - sum_w を超える最初の要素の index) - 1
      int idx = lower_bound(P.begin(), P.begin() + m, tmp) - P.begin() - 1;
      ans = max(ans, sum_v + P.at(idx).second);
    }
  }
  cout << ans << endl;
}