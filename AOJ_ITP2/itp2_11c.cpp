// ITP2 11_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> T(K);
  for (int i = 0; i < K; i++) cin >> T.at(i);
  sort(T.begin(), T.end());
  for (int tmp = 0; tmp < (1 << K); tmp++) {
    int idx = 0;
    for (int i = 0; i < K; i++) {
      if ((tmp >> i) & 1) idx |= (1 << T.at(i));
    }
    cout << idx << ":";
    for (int i = 0; i < K; i++) {
      if ((tmp >> i) & 1) cout << " " << T.at(i);
    }
    cout << endl;
  }
}