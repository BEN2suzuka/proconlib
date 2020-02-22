// ALDS1 7_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// 木の復元
// ex.
// Preorder : [1], 2, 3, 4, 5, 6, 7, 8, 9
// Inorder  : 3, 2, 5, 4, 6, [1], 8, 7, 9
// 1 を根とする木は、3 2 5 4 6 の左部分木と 8 7 9 の右部分木に分かれる

int N;
int pos;
vector<int> A, B, C;

// Postorder を返す
void func(int left, int right) {
  if (right - left < 1) return;
  int root = A.at(pos);
  pos++;
  int mid = distance(B.begin(), find(B.begin(), B.end(), root));
  func(left, mid);  // root の左部分木
  func(mid + 1, right);  // root の右部分木
  C.push_back(root);  // root は最後
}

int main() {
  cin >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  func(0, N);
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << C.at(i);
  }
  cout << endl;
}