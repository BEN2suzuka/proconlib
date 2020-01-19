// ALDS1 9_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 最大ヒープ
// max-ヒープ条件 : 節点のキーがその親のキー以下である
int N;
vector<int> A;

void maxHeapify(int i) {
  int largest;
  int left = 2*i;  // 左の子
  int right = 2*i + 1;  // 右の子

  // 左の子、自分、右の子で値が最大のノードを選ぶ
  if (left <= N && A.at(left) > A.at(i)) largest = left;
  else largest = i;
  if (right <= N && A.at(right) > A.at(largest)) largest = right;

  // max-ヒープ条件を満たすまで木の葉に向かって下降
  if (largest != i) {
    swap(A.at(i), A.at(largest));
    maxHeapify(largest);
  }
}

int main() {
  cin >> N;
  A.resize(N+1);
  for (int i = 1; i <= N; i++) cin >> A.at(i);
  for (int i = N/2; i >= 1; i--) maxHeapify(i);  // N/2 から降順
  for (int i = 1; i <= N; i++) cout << " " << A.at(i);
  cout << endl;
}