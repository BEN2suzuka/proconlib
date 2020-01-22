// ALDS1 5_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 転倒数 (分割統治法による解法)
long long mergeSort(vector<int> &A, int left, int right) {
  if (right - left == 1) return 0;
  int mid = (left + right) / 2;
  long long v1 = mergeSort(A, left, mid);  // 左半分の転倒数
  long long v2 = mergeSort(A, mid, right);  // 右半分の転倒数

  vector<int> buf;
  for (int i = left; i < mid; i++) buf.push_back(A.at(i));
  for (int i = right - 1; i >= mid; i--) buf.push_back(A.at(i));

  long long v3 = 0;  // マージの際に生じる反転数
  int tmp = mid - left;
  int iter_left = 0;
  int iter_right = buf.size() - 1;
  for (int i = left; i < right; i++) {
    if (buf.at(iter_left) <= buf.at(iter_right)) {
      A.at(i) = buf.at(iter_left);
      iter_left++;
      tmp--;
    }
    else {
      A.at(i) = buf.at(iter_right);
      iter_right--;
      v3 += tmp;
    }
  }
  return v1 + v2 + v3;
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  cout << mergeSort(A, 0, N) << endl;
}