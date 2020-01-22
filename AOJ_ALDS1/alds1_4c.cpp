// ALDS1 4_C
// C++14

// TLE します

#include <bits/stdc++.h>
using namespace std;

const int M = 1046527;
vector<string> H(M);

int getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getKey(string str) {
  long long sum = 0;
  int p = 1;
  for (int i = 0; i < str.size(); i++) {
    sum += p * getChar(str.at(i));
    p *= 5;
  }
  return sum;
}

int h1(long long key) { return key % M; }

int h2(long long key) { return 1 + (key % (M-1)); }

int find(string str) {
  long long key = getKey(str);
  int i = 0;
  while (1) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H.at(h) == str) return 1;
    if (H.at(h) == "") return 0;
    i++;
  }
  return 0;
}

int insert(string str) {
  long long key = getKey(str);
  int i = 0;
  while (1) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H.at(h) == str) return 1;
    if (H.at(h) == "") {
      H.at(h) = str;
      return 0;
    }
  }
  return 0;
}

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    string com, str; cin >> com >> str;
    if (com.at(0) == 'i') insert(str);
    else {
      if (find(str)) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
}