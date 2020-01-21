// ALDS1 2_C
// C++14
#include <bits/stdc++.h>
using namespace std;

struct Card {
  char mark;
  int num;
};

void bubble(vector<Card> &A, int N) {
  bool flag = true;
  int i = 0;
  while (flag) {
    flag = false;
    for (int j = N-1; j >= i+1; j--) {
      if (A.at(j).num < A.at(j-1).num) {
        swap(A.at(j), A.at(j-1));
        flag = true;
      }
    }
    i++;
  }
}

void selection(vector<Card> &A, int N) {
  int minj;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if (A.at(j).num < A.at(minj).num) minj = j;
    }
    if (minj != i) swap(A.at(i), A.at(minj));
  }
}

void print(vector<Card> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << A.at(i).mark << A.at(i).num;
  }
  cout << endl;
}

bool isStable(vector<Card> C1, vector<Card> C2, int N) {
  for (int i = 0; i < N; i++) {
    if (C1.at(i).mark != C2.at(i).mark) return false;
  }
  return true;
}

int main() {
  int N; cin >> N;
  vector<Card> C1(N), C2(N);
  for (int i = 0; i < N; i++) cin >> C1.at(i).mark >> C1.at(i).num;
  for (int i = 0; i < N; i++) C2.at(i) = C1.at(i);
  bubble(C1, N);
  selection(C2, N);
  print(C1, N);
  cout << "Stable" << endl;  // バブルソートは安定なソート
  print(C2, N);
  if (isStable(C1, C2, N)) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
}