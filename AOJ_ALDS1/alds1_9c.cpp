// ALDS1 9_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 優先度付きキュー
int idx = 0;
vector<int> A(2000010);
const int INF = 1000000007;

void maxHeapify(int i) {
  int largest;
  int left = 2*i;
  int right = 2*i + 1;

  if (left <= idx && A.at(left) > A.at(i)) largest = left;
  else largest = i;
  if (right <= idx && A.at(right) > A.at(largest)) largest = right;

  if (largest != i) {
    swap(A.at(i), A.at(largest));
    maxHeapify(largest);
  }
}

// 最大の要素を取得・削除
int extract() {
  if (idx < 1) return -INF;  // error
  int res = A.at(1);
  A.at(1) = A.at(idx);  // 末尾の値を根に移す
  idx--;
  maxHeapify(1);
  return res;
}

// max-ヒープ条件を満たすように根に向かって正しい位置へ移動
void increaseKey(int i, int key) {
  if (key < A.at(i)) return;  // A.at(i) は -INF
  A.at(i) = key;
  while (i > 1 && A.at(i/2) < A.at(i)) {
    swap(A.at(i), A.at(i/2));
    i = i / 2;
  }
}

// 末尾に挿入
void insert(int key) {
  idx++;
  A.at(idx) = -INF;
  increaseKey(idx, key);
}

int main() {
  string com;
  while (1) {
    cin >> com;
    if (com == "end") break;
    if (com == "insert") {
      int k; cin >> k;
      insert(k);
    }
    if (com == "extract") cout << extract() << endl;
  }
}