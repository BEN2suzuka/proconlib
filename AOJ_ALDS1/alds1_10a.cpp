// ALDS1 10_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> dp(50);
  dp.at(0) = 1;
  dp.at(1) = 1;
  for (int i = 0; i < N; i++) {
    dp.at(i+2) = dp.at(i+1) + dp.at(i);
  }
  cout << dp.at(N) << endl;
}