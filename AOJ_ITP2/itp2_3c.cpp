// ITP2 3_C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int b, e, k; cin >> b >> e >> k;
    int cnt = 0;
    for (int j = b; j < e; j++) {
      if (A.at(j) == k) cnt++;
    }
    cout << cnt << endl;
  }
}