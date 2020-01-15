// ALDS1 6_A
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  // 計数ソート
  const int MAX = 10001;  // A の要素の最大値 + 1
  vector<int> C(MAX);  // A に含まれる要素 i の個数
  for (int i = 0; i < N; i++) C.at(A.at(i))++;

  vector<int> S(MAX);  // C の累積和
  S.at(0) = C.at(0);
  for (int i = 1; i < MAX; i++) S.at(i) = S.at(i-1) + C.at(i);

  vector<int> sorted(N);
  for (int i = N-1; i >= 0; i--) {
    S.at(A.at(i))--;
    sorted.at(S.at(A.at(i))) = A.at(i);
  }

  // 出力
  for (int i = 0; i < N-1; i++) cout << sorted.at(i) << " ";
  cout << sorted.at(N-1) << endl;
}