// ALDS1 3_A
// C++14
#include <bits/stdc++.h>
using namespace std;

int top;
int MAX = 1000;
vector<int> S(MAX);

void initialize() {
  top = 0;
}

bool isEmpty() {
  return top == 0;
}

bool isFull() {
  return top >= MAX-1; 
}

void push(int x) {
  if (isFull()) return;  // エラー
  top++;
  S.at(top) = x;
}

int pop() {
  if (isEmpty()) return 0;  // エラー
  top--;
  return S.at(top+1);
}

int main() {
  initialize();
  string s;
  int a, b;
  while (cin >> s) {
    if (s == "+") {
      a = pop(); b = pop();
      push(a + b);
    }
    else if (s == "-") {
      a = pop(); b = pop();
      push(b - a);
    }
    else if (s == "*") {
      a = pop(); b = pop();
      push(a * b);
    }
    else {
      push(stoi(s));
    }
  }
  cout << S.at(top) << endl;
}