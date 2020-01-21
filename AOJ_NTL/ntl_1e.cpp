// NTL 1_E
// C++14
#include <bits/stdc++.h>
using namespace std;

// 拡張ユークリッドの互除法
// ax + by = gcd(a, b) を解く

// gcd(a, b) を返す
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
    int a, b; cin >> a >> b;
    long long x, y;
    extGCD(a, b, x, y);
    cout << x << " " << y << endl;
}