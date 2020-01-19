// ALDS1 8_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分探索木 : 挿入
struct Node {
  int key;
  Node *parent, *left, *right;  // 親、左の子、右の子へのポインタ
};

Node *root, *NIL;

void insert(int k) {
  Node *prev = NIL;  // 1 階層上
  Node *cur = root;  // 現在地
  Node *z;  // 挿入するノード

  z = (Node*)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  // NIL に当たるまで潜る
  // 空のとき、root == NIL
  while (cur != NIL) {
    prev = cur;
    if (z->key < cur->key) {  // z が今いるノードより小さいとき、左の子の方へ潜る
      cur = cur->left;
    }
    else {
      cur = cur->right;
    }
  }

  z->parent = prev;  // 1 階層上が z の親 (以下、親)
  if (prev == NIL) {  // 親がいない場合、z は根
    root = z;
  }
  else {
    if (z->key < prev->key) {  // z が親より小さいとき、z は親の左の子へ
      prev->left = z;
    }
    else {
      prev->right = z;
    }
  }
}

void inorder(Node *node) {
  if (node == NIL) return;
  inorder(node->left);
  cout << " " << node->key;
  inorder(node->right);
}

void preorder(Node *node) {
  if (node == NIL) return;
  cout << " " << node->key;
  preorder(node->left);
  preorder(node->right);
}

int main() {
  int M; cin >> M;
  for (int i = 0; i < M; i++) {
    string com; cin >> com;
    if (com == "insert") {
      int k; cin >> k;
      insert(k);
    }
    else {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}