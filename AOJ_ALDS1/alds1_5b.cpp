// ALDS1 5_B
// C++
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
const int INF = 1000000007;

void MergeSort(vector<int> &A, int left, int right) {
  // divide
  if (right - left == 1) return;
  int mid = left + (right - left) / 2;
  MergeSort(A, left, mid);  // [left, mid)
  MergeSort(A, mid, right);  // [mid, right)

  vector<int> L, R;
  for (int i = left; i < mid; i++) L.push_back(A.at(i));
  for (int i = mid; i < right; i++) R.push_back(A.at(i));
  L.push_back(INF);
  R.push_back(INF);

  // merge
  int iter_left = 0;
  int iter_right = 0;
  for (int i = left; i < right; i++) {
    if (L.at(iter_left) <= R.at(iter_right)) {
      A.at(i) = L.at(iter_left);
      iter_left++;
    }
    else {
      A.at(i) = R.at(iter_right);
      iter_right++;
    }
    cnt++;
  }
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  MergeSort(A, 0, N);

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
  cout << cnt << endl;
}