// ALDS1 2_D
// C++14
#include <bits/stdc++.h>
using namespace std;

// シェルソート
// G[i] : G[n+1] = 3 * G[n] + 1
// 間隔 g だけ離れた要素のみに挿入ソートを行っていく
// 間隔 g を小さくしていく
// 最後は g = 1 の挿入ソート (普通の挿入ソート)

vector<int> G;
int cnt = 0;

void insertionSort(vector<int> &A, int N, int g) {
  for (int i = g; i < N; i++) {
    int tmp = A.at(i);
    int j = i - g;
    while (j >= 0 && A.at(j) > tmp) {
      A.at(j+g) = A.at(j);
      j -= g;
      cnt++;
    }
    A.at(j+g) = tmp;
  }
}

void shellSort(vector<int> &A, int N) {
  int i = 1;
  while (i <= N) {
    G.push_back(i);
    i = 3*i + 1;
  }
  for (int j = G.size()-1; j >= 0; j--) {
    insertionSort(A, N, G.at(j));
  }
}

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  shellSort(A, N);
  cout << G.size() << endl;
  for (int i = G.size()-1; i >= 0; i--) {
    cout << G.at(i);
    if (i) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < N; i++) cout << A.at(i) << endl;
}