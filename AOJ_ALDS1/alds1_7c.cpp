// ALDS1 7_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分木の巡回
struct Node {
  int parent;
  int left;
  int right;
};

vector<Node> T;

const int NIL = -1;  // null

// 先行順巡回 (根節点、左部分木、右部分木の順)
void preParse(int node) {
  if (node == NIL) return;
  cout << " " << node;
  preParse(T.at(node).left);
  preParse(T.at(node).right);
}

// 中間順巡回 (左部分木、根節点、右部分木の順)
void inParse(int node) {
  if (node == NIL) return;
  inParse(T.at(node).left);
  cout << " " << node;
  inParse(T.at(node).right);
}

// 後行順巡回 (左部分木、右部分木、根節点の順)
void postParse(int node) {
  if (node == NIL) return;
  postParse(T.at(node).left);
  postParse(T.at(node).right);
  cout << " " << node;
}

int main() {
  int N; cin >> N;
  T.resize(N);
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
  cout << "Preorder" << endl;
  preParse(root);
  cout << endl;
  cout << "Inorder" << endl;
  inParse(root);
  cout << endl;
  cout << "Postorder" << endl;
  postParse(root);
  cout << endl;
}