// ALDS1 5_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 転倒数 (分割統治法による解法)
long long MergeSort(vector<int> &A, int left, int right) {
  if (right - left == 1) return 0;
  int mid = (left + right) / 2;
  long long v1 = MergeSort(A, left, mid);  // 左半分の転倒数
  long long v2 = MergeSort(A, mid, right);  // 右半分の転倒数

  vector<int> L, R;
  for (int i = left; i < mid; i++) L.push_back(A.at(i));
  for (int i = mid; i < right; i++) R.push_back(A.at(i));
  const int INF = 1000000007;
  L.push_back(INF);
  R.push_back(INF);

  long long v3 = 0;  // マージの際に生じる反転数
  int tmp = L.size() - 1;
  int iter_left = 0;
  int iter_right = 0;
  for (int i = left; i < right; i++) {
    if (L.at(iter_left) <= R.at(iter_right)) {
      A.at(i) = L.at(iter_left);
      iter_left++;
      tmp--;
    }
    else {
      A.at(i) = R.at(iter_right);
      iter_right++;
      v3 += tmp;
    }
  }
  return v1 + v2 + v3;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  cout << MergeSort(A, 0, N) << endl;
}