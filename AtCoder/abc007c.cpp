// ABC 007 C
// C++14
#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> G;
vector<vector<int>> visited;
queue<vector<int>> tovisit;
vector<int> dy = { 1, -1, 0, 0 };
vector<int> dx = { 0, 0, -1, 1 };

void bfs() {
  int y = tovisit.front().at(0);
  int x = tovisit.front().at(1);
  tovisit.pop();
  for (int i = 0; i < 4; i++) {
    int ny = y + dy.at(i);
    int nx = x + dx.at(i);
    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if (G.at(ny).at(nx) == '#') continue;
    if (visited.at(ny).at(nx) != -1) continue;
    visited.at(ny).at(nx) = visited.at(y).at(x) + 1;
    tovisit.push({ ny, nx });
  }
}

int main() {
  int sy, sx, gy, gx;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--; sx--; gy--; gx--;
  G.resize(R);
  for (int i = 0; i < R; i++) cin >> G.at(i);
  visited = vector<vector<int>>(R, vector<int>(C, -1));
  tovisit.push({ sy, sx });
  visited.at(sy).at(sx) = 0;
  while (!tovisit.empty()) bfs();
  cout << visited.at(gy).at(gx) << endl;
}