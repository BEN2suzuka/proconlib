// C++14
#include <bits/stdc++.h>
using namespace std;

// エラトステネスのふるい
// isPrime[i] = true <=> i は素数
// ans には N 以下の素数を格納
// cnt には N 以下の素数の個数
int main() {
  int N; cin >> N;
  vector<bool> isPrime(N+1, true);
  isPrime.at(0) = false;
  isPrime.at(1) = false;
  vector<int> ans;
  for (int i = 2; i*i <= N; i++) {
    if (isPrime.at(i)) {
      ans.push_back(i);
      for (int j = 2*i; j <= N; j += i) isPrime.at(j) = false;
    }
  }
  int cnt = 0;
  for (int i = 2; i <= N; i++) {
    if (isPrime.at(i)) cnt++;
  }
  cout << cnt << endl;
}