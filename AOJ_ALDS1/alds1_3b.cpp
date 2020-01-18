// ALDS1 3_B
// C++14
#include <bits/stdc++.h>
using namespace std;

int head, tail;
int MAX = 100010;
vector<pair<string, int>> Q(MAX);

void initialize() {
  head = 0; tail = 0;
}

bool isEmpty() {
  return head == tail;
}

bool isFull() {
  return head == (tail + 1) % MAX;
}

void enqueue(pair<string, int> p) {
  if (isFull()) return;  // error
  Q.at(tail) = p;
  tail = (tail + 1) % MAX;
}

pair<string, int> dequeue() {
  if (isEmpty()) return pair<string, int>("error", 0);
  pair<string, int> p = Q.at(head);
  head = (head + 1) % MAX;
  return p;
}

int main() {
  initialize();
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    string name; cin >> name;
    int time; cin >> time;
    enqueue(make_pair(name, time));
  }

  int cur_time = 0;
  while (!isEmpty()) {
    pair<string, int> p = dequeue();
    if (p.second - q > 0) {
      cur_time += q;
      p.second -= q;
      enqueue(p);
    }
    else {
      cur_time += p.second;
      cout << p.first << " " << cur_time << endl;
    }
  }
}