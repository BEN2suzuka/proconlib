// ALDS1 3_C
// C++14

// TLE します
// scanf を使うなど、高速な入出力方法を使う必要があるそう

#include <bits/stdc++.h>
using namespace std;

// ポインタ変数はメモリのアドレスを格納
// 型 *変数名 でポインタ変数を宣言

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;  // 番兵。番兵は先頭に置く

void init() {
  // 指定したサイズだけメモリを動的に確保する
  nil = (Node*)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

// 先頭、すなわち番兵の直後にノードを追加
void insert(int key) {
  Node *x = (Node*)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

// 与えられたキーを持つノードを探し、そのポインタを返す
// O(N) の計算量
Node* listSearch(int key) {
  Node *cur = nil->next;  // 先頭のノード、すなわち番兵の次のノードから
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

// ポインタを繋ぎ変えて、指定ノードを削除
void deleteNode(Node *t) {
  if (t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);  // 先頭、すなわち番兵の次
}

void deleteLast() {
  deleteNode(nil->prev);  // 先頭、すなわち番兵の前
}

void deleteKey(int key) {
  deleteNode(listSearch(key));
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while (1) {
    if (cur == nil) break;
    if (isf) cout << " ";
    isf++;
    cout << cur->key;
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  init();
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    string com; cin >> com;
    if (com == "insert") {
      int x; cin >> x;
      insert(x);
    }
    else if (com == "delete") {
      int x; cin >> x;
      deleteKey(x);
    }
    else if (com == "deleteFirst") deleteFirst();
    else deleteLast();
  }
  printList();
}