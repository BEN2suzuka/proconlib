// DSL 2_C
// C++14
#include <bits/stdc++.h>
using namespace std;

// kD 木
const int N = 500000;
const int NIL = -1;
struct Node {int location, parent, left, right; };
struct Point {int id, x, y; };
vector<Node> T(N);  // 二分探索木
vector<Point> P(N);
vector<int> ans;
int np = 0;  // ノード番号

// ソートの比較関数
bool lessX(Point &a, Point &b) { return a.x < b.x; }
bool lessY(Point &a, Point &b) { return a.y < b.y; }

// r-l 個 (l 番目から r-1 番目) の点から二分探索木を構築
int makekDTree(int l, int r, int depth) {
  if (!(l < r)) return NIL;
  // x (または y) について昇順に整列
  if (depth % 2 == 0) {
    sort(P.begin() + l, P.begin() + r, lessX);
  }
  else {
    sort(P.begin() + l, P.begin() + r, lessY);
  }
  int mid = (l + r) / 2;  // 中央値の index
  int t = np;  // ノード番号
  np++;
  T.at(t).location = mid;
  T.at(t).left = makekDTree(l, mid, depth + 1);  // 左の子
  T.at(t).right = makekDTree(mid + 1, r, depth + 1);  // 右の子
  return t;
}

// ノード番号 v を根とする探索
void find(int v, int sx, int tx, int sy, int ty, int depth) {
  int idx = T.at(v).location;
  int x = P.at(idx).x;
  int y = P.at(idx).y;
  // 条件を満たす点の id を追加
  if (sx <= x && x <= tx && sy <= y && y <= ty) ans.push_back(P.at(idx).id);
  if (depth % 2 == 0) {
    if (T.at(v).left != NIL && sx <= x) {
      find(T.at(v).left, sx, tx, sy, ty, depth + 1);
    }
    if (T.at(v).right != NIL && x <= tx) {
      find(T.at(v).right, sx, tx, sy, ty, depth + 1);
    }
  }
  else {
    if (T.at(v).left != NIL && sy <= y) {
      find(T.at(v).left, sx, tx, sy, ty, depth + 1);
    }
    if (T.at(v).right != NIL && y <= ty) {
      find(T.at(v).right, sx, tx, sy, ty, depth + 1);
    }
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &P.at(i).x, &P.at(i).y);
    P.at(i).id = i;
  }
  int root = makekDTree(0, n, 0);
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int sx, tx, sy, ty;
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(root, sx, tx, sy, ty, 0);
    sort(ans.begin(), ans.end());
    for (auto i : ans) printf("%d\n", i);
    printf("\n");
  }
}