// DPL 4_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 半分全列挙
// O(N^4) -> O(N^2 * logN) に改善
int main() {
  int N; cin >> N;
  long long V; cin >> V;
  vector<long long> A(N), B(N), C(N), D(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  for (int i = 0; i < N; i++) cin >> C.at(i);
  for (int i = 0; i < N; i++) cin >> D.at(i);
  vector<long long> CD(N*N);
  // C と D の全ての取り出し方を列挙
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      CD.at(i*N + j) = C.at(i) + D.at(j);
    }
  }
  sort(CD.begin(), CD.end());
  long long ans = 0;
  // A と B の全ての取り出し方を列挙
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      long long ab = A.at(i) + B.at(j);
      long long cd = V - ab;
      // C と D の和が cd となる取り出し方の総数を求める
      ans += upper_bound(CD.begin(), CD.end(), cd) - lower_bound(CD.begin(), CD.end(), cd);
    }
  }
  cout << ans << endl;
}