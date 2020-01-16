// ITP2 5_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;
    A.at(i) = make_pair(x, y);
  }
  sort(A.begin(), A.end());
  for (auto p : A) cout << p.first << " " << p.second << endl;
}