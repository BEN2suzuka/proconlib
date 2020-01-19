// ALDS1 7_A
// C++14
#include <bits/stdc++.h>
using namespace std;

// 根付き木 (左子右兄弟表現) の実装
struct Node {
  int parent;
  int left;  // 最も左の子
  int right;  // すぐ右の兄弟
};

vector<Node> T;
vector<int> D;  // 各節点の深さ

const int NIL = -1;  // null を表す

void print(int node) {
  cout << "node " << node << ": ";
  cout << "parent = " << T.at(node).parent << ", ";
  cout << "depth = " << D.at(node) << ", ";
  if (T.at(node).parent == NIL) cout << "root, ";
  else if (T.at(node).left == NIL) cout << "leaf, ";
  else cout << "internal node, ";
  cout << "[";
  int idx = 0;
  int c = T.at(node).left;
  while (c != NIL) {
    if (idx) cout << ", ";
    cout << c;
    c = T.at(c).right;
    idx++;
  }
  cout << "]" << endl;
}

// 右の兄弟の深さと最も左の子の深さを再帰的に計算
int setDepth(int node, int depth) {
  D.at(node) = depth;
  // 右の兄弟が存在する場合、深さを変えずに再帰呼び出し
  if (T.at(node).right != NIL) {
    setDepth(T.at(node).right, depth);
  }
  // 左の子が存在する場合、深さを 1 足して再帰呼び出し
  if (T.at(node).left != NIL) {
    setDepth(T.at(node).left, depth + 1);
  }
}

int main() {
  int N; cin >> N;
  T.resize(N);
  D.resize(N);
  // 初期化 (存在しないものは NIL とする)
  for (int i = 0; i < N; i++) {
    T.at(i).parent = NIL;
    T.at(i).left = NIL;
    T.at(i).right = NIL;
  }
  for (int i = 0; i < N; i++) {
    int id, k; cin >> id >> k;
    int tmp = 0;
    for (int j = 0; j < k; j++) {
      int c; cin >> c;
      if (j == 0) T.at(id).left = c;
      else T.at(tmp).right = c;
      T.at(c).parent = id;
      tmp = c;
    }
  }
  int root = NIL;
  for (int i = 0; i < N; i++) {
    if (T.at(i).parent == NIL) root = i;
  }
  setDepth(root, 0);
  for (int i = 0; i < N; i++) print(i);
}