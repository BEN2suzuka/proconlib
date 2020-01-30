// DSL 3_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// スライド最小値
// deque に最小値の index を保持
int main() {
  int N, L; cin >> N >> L;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  deque<int> deq;
  // index (0, 1, ..., N-1) を追加
  for (int i = 0; i < N; i++) {
    // deque の末尾の値 j が a_j >= a_i
    while (!deq.empty() && A.at(deq.back()) >= A.at(i)) deq.pop_back();
    // 空、あるいは a_j < a_i
    deq.push_back(i);
    // L 個追加以降
    if (i >= L-1) {
      if (i != L-1) cout << " ";
      cout << A.at(deq.front());
    }
    // 次から範囲外
    if (deq.front() == i - (L - 1)) deq.pop_front();
  }
  cout << endl;
}