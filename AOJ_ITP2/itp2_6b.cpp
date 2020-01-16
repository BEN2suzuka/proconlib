// ITP2 6_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int M; cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) cin >> B.at(i);

  for (int i = 0; i < M; i++) {
    int key = B.at(i);
    bool found = false;
    int left = 0, right = N;
    while (left < right) {
      int mid = (left + right) / 2;
      if (A.at(mid) == key) { found = true; break; }
      else if (key < A.at(mid)) right = mid;
      else left = mid + 1;
    }
    if (!found) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}