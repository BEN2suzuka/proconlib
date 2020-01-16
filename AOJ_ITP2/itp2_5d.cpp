// ITP2 5_D
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) A.at(i) = i+1;
  do {
    for (int i = 0; i < N-1; i++) cout << A.at(i) << " ";
    cout << A.at(N-1) << endl;
  } while (next_permutation(A.begin(), A.end()));
}