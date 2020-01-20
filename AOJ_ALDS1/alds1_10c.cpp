// ALDS1 10_C
// C++14
#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    string X, Y; cin >> X >> Y;
    vector<vector<int>> dp(X.size()+1, vector<int>(Y.size()+1, 0));
    for (int i = 0; i < X.size(); i++) {
      for (int j = 0; j < Y.size(); j++) {
        if (X.at(i) == Y.at(j)) {
          dp.at(i+1).at(j+1) = dp.at(i).at(j) + 1;
        }
        else {
          dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j), dp.at(i).at(j+1));
        }
      }
    }
    cout << dp.at(X.size()).at(Y.size()) << endl;
  }
}