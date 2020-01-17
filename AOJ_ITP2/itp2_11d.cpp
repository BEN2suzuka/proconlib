// ITP2 11_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if ((tmp >> i) & 1) cnt++;
    }
    if (cnt != K) continue;
    cout << tmp << ":";
    for (int i = 0; i < N; i++) {
      if ((tmp >> i) & 1) cout << " " << i;
    }
    cout << endl;
  }
}