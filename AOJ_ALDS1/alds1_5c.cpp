// ALDS1 5_C
// C++14
#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

// 線分の端点 a, b
void koch(int N, Point a, Point b) {
  if (N == 0) return;
  Point s, t, u;
  double PI = acos(-1);
  int deg = 60;
  double rad = deg * PI / 180;

  // s, t : 線分 ab を三等分する点
  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  // u : su, ut, ts が正三角形を成すような点
  // 原点中心の回転行列
  // [ cos -sin ][x]
  // [ sin  cos ][y]
  // u : s を中心に t を反時計回りに 60 度回転した点
  u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
  u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;

  koch(N-1, a, s);
  cout << s.x << " " << s.y << endl;
  koch(N-1, s, u);
  cout << u.x << " " << u.y << endl;
  koch(N-1, u, t);
  cout << t.x << " " << t.y << endl;
  koch(N-1, t, b);
}

int main() {
  int N; cin >> N;
  Point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;
  cout << fixed << setprecision(8);
  cout << a.x << " " << a.y << endl;
  koch(N, a, b);
  cout << b.x << " " << b.y << endl;
}