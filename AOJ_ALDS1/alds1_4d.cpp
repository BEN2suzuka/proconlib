// ALDS1 4_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分探索
// P が増加したとき、K 台で積める荷物数は減少することはない
int N, K;
vector<int> W;

// 最大積載量 P のトラック K 台で積める荷物の数を返す
int func(int P) {
  int i = 0;  // 荷物数
  for (int j = 0; j < K; j++) {
    int s = 0;
    while (s + W.at(i) <= P) {
      s += W.at(i);
      i++;
      if (i == N) return N;  // すべて積めた
    }
  }
  return i;
}

int main() {
  cin >> N >> K;
  W.resize(N);
  for (int i = 0; i < N; i++) cin >> W.at(i);

  // 答えとなる P を [0, 1000000000] で二分探索
  int left = 0;  // 絶対 NG
  int right = 100000 * 10000;  // 絶対 OK
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (func(mid) == N) right = mid;
    else left = mid;
  }
  cout << right << endl;
}