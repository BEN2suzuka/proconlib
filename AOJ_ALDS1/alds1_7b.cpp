// ALDS1 7_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分木の実装
struct Node {
  int parent;
  int left;  // 左の子
  int right;  // 右の子
};

vector<Node> T;
vector<int> D;  // 深さ
vector<int> H;  // 高さ

const int NIL = -1;  // null

// 深さを再帰的に計算
void setDepth(int node, int depth) {
  if (node == NIL) return;
  D.at(node) = depth;
  setDepth(T.at(node).left, depth + 1);
  setDepth(T.at(node).right, depth + 1);
}

// 左の子の高さ + 1 と右の子の高さ + 1 のうち大きい方を採用
int setHeight(int node) {
  int h1 = 0, h2 = 0;
  if (T.at(node).left != NIL) h1 = setHeight(T.at(node).left) + 1;
  if (T.at(node).right != NIL) h2 = setHeight(T.at(node).right) + 1;
  H.at(node) = max(h1, h2);
  return H.at(node);
}

// 兄弟を返す
int getSibling(int node) {
  if (T.at(node).parent == NIL) return NIL;
  if (T.at(T.at(node).parent).left != node && T.at(T.at(node).parent).left != NIL) {
    return T.at(T.at(node).parent).left;
  }
  if (T.at(T.at(node).parent).right != node && T.at(T.at(node).parent).right != NIL) {
    return T.at(T.at(node).parent).right;
  }
  return NIL;
}

void print(int node) {
  cout << "node " << node << ": ";
  cout << "parent = " << T.at(node).parent << ", ";
  cout << "sibling = " << getSibling(node) << ", ";
  int degree = 0;
  if (T.at(node).left != NIL) degree++;
  if (T.at(node).right != NIL) degree++;
  cout << "degree = " << degree << ", ";
  cout << "depth = " << D.at(node) << ", ";
  cout << "height = " << H.at(node) << ", ";
  if (T.at(node).parent == NIL) {
    cout << "root" << endl;
  }
  else if (T.at(node).left == NIL && T.at(node).right == NIL) {
    cout << "leaf" << endl;
  }
  else {
    cout << "internal node" << endl;
  }
}

int main() {
  int N; cin >> N;
  T.resize(N);
  D.resize(N);
  H.resize(N);
  // 初期化
  for (int i = 0; i < N; i++) {
    T.at(i).parent = NIL;
    T.at(i).left = NIL;
    T.at(i).right = NIL;
  }
  for (int i = 0; i < N; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    T.at(id).left = l;
    T.at(id).right = r;
    if (l != NIL) T.at(l).parent = id;
    if (r != NIL) T.at(r).parent = id;
  }
  int root = NIL;
  for (int i = 0; i < N; i++) {
    if (T.at(i).parent == NIL) root = i;
  }
  setDepth(root, 0);
  setHeight(root);
  for (int i = 0; i < N; i++) print(i);
}