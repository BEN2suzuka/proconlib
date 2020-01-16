// ITP2 3_D
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int M; cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) cin >> B.at(i);

  int i = 0;
  while (i < N && i < M) {
    if (A.at(i) == B.at(i)) {
      i++;
      continue;
    }
    else if (A.at(i) < B.at(i)) {
      cout << 1 << endl;
      return 0;
    }
    else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (N < M) cout << 1 << endl;
  else cout << 0 << endl;
}