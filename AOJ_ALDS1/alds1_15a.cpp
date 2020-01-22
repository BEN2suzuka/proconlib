// ALDS1 15_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A = { 25, 10, 5, 1 };
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    int tmp = N / A.at(i);  // その硬貨を使う枚数
    N -= A.at(i) * tmp;
    ans += tmp;
  }
  cout << ans << endl;
}