// ITP2 3_A
// C++
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(3);
  for (int i = 0; i < 3; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  cout << A.at(0) << " " << A.at(2) << endl;
}