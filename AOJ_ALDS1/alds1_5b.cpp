// ALDS1 5_B
// C++
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void MergeSort(vector<int> &A, int left, int right) {
  // divide
  if (right - left == 1) return;
  int mid = left + (right - left) / 2;
  MergeSort(A, left, mid);  // [left, mid)
  MergeSort(A, mid, right);  // [mid, right)

  // ex. buf = { 2, 5, 6, 8, 7, 4, 3, 1 }
  vector<int> buf;
  for (int i = left; i < mid; i++) buf.push_back(A.at(i));
  for (int i = right-1; i >= mid; i--) buf.push_back(A.at(i));

  // merge
  int iter_left = 0;
  int iter_right = buf.size() - 1;
  for (int i = left; i < right; i++) {
    if (buf.at(iter_left) <= buf.at(iter_right)) {
      A.at(i) = buf.at(iter_left);
      iter_left++;
    }
    else {
      A.at(i) = buf.at(iter_right);
      iter_right--;
    }
    cnt++;
  }
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  MergeSort(A, 0, N);

  // 出力
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
  cout << cnt << endl;
}