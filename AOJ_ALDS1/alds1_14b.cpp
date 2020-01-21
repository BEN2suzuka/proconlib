// ALDS1 14_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// KMP : Knuth–Morris–Pratt algorithm
// T : テキスト, P : パターン
vector<int> KMP(string T, string P) {

  // 部分マッチテーブルの生成
  // ex.
  //   i     0  1  2  3  4  5  6
  //  P[i]   A  B  C  D  A  B  D
  // pat[i] -1  0  0  0  0  1  2
  vector<int> pat(P.size()+1);
  pat.at(0) = -1;
  int j = -1;
  for (int i = 0; i < P.size(); i++) {
    while (j >= 0 && P.at(i) != P.at(j)) j = pat.at(j);
    j++;
    pat.at(i+1) = j;
  }

  vector<int> res;
  int t = 0;  // T の index
  int p = 0;  // P の index
  while (t + p < T.size()) {
    if (P.at(p) == T.at(t+p)) {
      p++;
      if (p == P.size()) {  // P と完全に一致
        res.push_back(t);
        t = t + p - pat.at(p);
        p = pat.at(p);
      }
    }
    else {  // 次の照合の開始位置を決める
      t += p - pat.at(p);
      if (p > 0) p = pat.at(p);
    }
  }
  return res;
}

int main() {
  string T, P; cin >> T >> P;
  vector<int> ans = KMP(T, P);
  for (auto v : ans) cout << v << endl;
}