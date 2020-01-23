// ALDS1 6_C
// C++14
#include <bits/stdc++.h>
using namespace std;

struct Card {
  char mark;
  int num;
};

void QuickSort(vector<Card> &A, int left, int right) {
  if (right - left <= 1) return;
  // パーティション
  Card x = A.at(right - 1);  // 基準値
  int i = left;
  for (int j = left; j < right; j++) {
    if (A.at(j).num <= x.num) {
      swap(A.at(i), A.at(j));
      i++;
    }
  }
  QuickSort(A, left, i-1);  // 基準値以下 (x は除く)
  QuickSort(A, i, right);  // 基準値より大きい
}

void MergeSort(vector<Card> &A, int left, int right) {
  if (right - left == 1) return;
  int mid = left + (right - left) / 2;
  MergeSort(A, left, mid);
  MergeSort(A, mid, right);

  vector<Card> L, R;
  for (int i = left; i < mid; i++) L.push_back(A.at(i));
  for (int i = mid; i < right; i++) R.push_back(A.at(i));
  const Card INF = { 'z', 1000000007 };
  L.push_back(INF);
  R.push_back(INF);

  int iter_left = 0;
  int iter_right = 0;
  for (int i = left; i < right; i++) {
    if (L.at(iter_left).num <= R.at(iter_right).num) {
      A.at(i) = L.at(iter_left);
      iter_left++;
    }
    else {
      A.at(i) = R.at(iter_right);
      iter_right++;
    }
  }
}

int main() {
  int N; cin >> N;
  vector<Card> A(N), B(N);
  for (int i = 0; i < N; i++) {
    char mark; cin >> mark;
    int num; cin >> num;
    A.at(i).mark = mark;
    B.at(i).mark = mark;
    A.at(i).num = num;
    B.at(i).num = num;
  }
  QuickSort(A, 0, N);
  MergeSort(B, 0, N);
  bool isStable = true;
  for (int i = 0; i < N; i++) {
    if (A.at(i).mark != B.at(i).mark) isStable = false;
  }
  if (isStable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  for (int i = 0; i < N; i++) {
    cout << A.at(i).mark << " " << A.at(i).num << endl;
  }
}