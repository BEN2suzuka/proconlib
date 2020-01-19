// ALDS1 8_B
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分探索木 : 探索
struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

// 空のとき、root == NIL
Node* find(Node *node, int k) {
  while (node != NIL && k != node->key) {
    if (k < node->key) node = node->left;
    else node = node->right;
  }
  return node;
}

void insert(int k) {
  Node *prev = NIL;
  Node *cur = root;
  Node *z;

  z = (Node*)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (cur != NIL) {
    prev = cur;
    if (z->key < cur->key) cur = cur->left;
    else cur = cur->right;
  }

  z->parent = prev;
  if (prev == NIL) root = z;
  else {
    if (z->key < prev->key) prev->left = z;
    else prev->right = z;
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
    if (com == "find") {
      int k; cin >> k;
      Node *n = find(root, k);
      if (n != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    }
    else if (com == "insert") {
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