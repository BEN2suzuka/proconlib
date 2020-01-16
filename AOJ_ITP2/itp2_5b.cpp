// ITP2 5_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<tuple<int, int, char, long long, string>> A(N);
  int v, w;
  char t;
  long long d;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> v >> w >> t >> d >> s;
    A.at(i) = make_tuple(v, w, t, d, s);
  }
  sort(A.begin(), A.end());
  for (auto a : A) {
    tie(v, w, t, d, s) = a;
    cout << v << " " << w << " " << t << " " << d << " " << s << endl;
  }
}