// ALDS1 8_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// 二分探索木 : 削除
struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;

// 節点 node を根とする部分木の中で最小の key をもつ節点を返す
Node* treeMinimum(Node *node) {
  while (node->left != NIL) node = node->left;
  return node;
}

Node* find(Node *node, int k) {
  while (node != NIL && k != node->key) {
    if (k < node->key) node = node->left;
    else node = node->right;
  }
  return node;
}

// 節点 node の次節点を返す
Node* treeSuccessor(Node *node) {
  // 節点 node に右の子が存在する場合は、右部分木で key 最小の節点が次節点
  if (node->right != NIL) return treeMinimum(node->right);
  // 存在しない場合は、親をたどって最初に「左の子になっているような節点の親」が次節点
  Node *y = node->parent;
  while (y != NIL && node == y->right) {
    node = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *y;  // 削除する節点
  Node *x;  // y の子

  // 螺旋本 p.220 Fig.9.3 参照
  // 削除する節点を決める
  if (z->left == NIL || z->right == NIL) {  // z が子を 1 つ以下もつとき
    y = z;  // z そのものとする
  }
  else {  // z が子を 2 つもつとき
    y = treeSuccessor(z);  // 中間順巡回における z の次節点とする
  }

  // y の子 x を決める
  // z が子をもたないとき -> x は z の右の子 (NIL)
  // z が子を 1 つもつとき -> x は z の子 (左右どちらか)
  // z が子を 2 つもつとき -> x は z の次節点の右の子 (次節点に左の子は存在しない)
  if (y->left != NIL) x = y->left;
  else x = y->right;

  // x の親が y の親になるように繋ぎ変える
  if (x != NIL) x->parent = y->parent;

  // y の親の子が x になるように繋ぎ変える
  if (y->parent == NIL) root = x;  // y が根のとき
  else {
    if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
  }

  // z が子を 2 つもつとき
  if (y != z) z->key = y->key;  // z の key に y の key を設定

  free(y);
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
    else if (com == "delete") {
      int k; cin >> k;
      treeDelete(find(root, k));
    }
    else {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}