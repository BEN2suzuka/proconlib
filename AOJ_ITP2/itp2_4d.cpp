// ITP2 4_D
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());  // ソートしてから
  A.erase(unique(A.begin(), A.end()), A.end());
  for (int i = 0; i < A.size(); i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
}