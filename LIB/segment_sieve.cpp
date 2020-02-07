// C++14
#include <bits/stdc++.h>
using namespace std;

// 区間ふるい 
// [a, b) に存在する素数の個数を返す
//
// 整数 n の素数判定 -> n が 2 から √n までの素数で割り切れるかどうか
// -> [a, b) の素数判定には √b 以下の素数を使う
// [2, √b) の bool 表と [a, b) の bool 表を別々に作る
// [2, √b) の素数 (2, 3, 5, 7, 11,...) の倍数を [a, b) から取り除く
int main() {
  long long a, b; cin >> a >> b;
  int L = sqrt(b);
  // is_prime[i - a] = true <=> i は素数
  vector<bool> is_prime(b-a, true);  // [a, b)
  vector<bool> is_prime_small(L+1);  // [2, √b)
  for (long long i = 0; i*i < b; i++) is_prime_small.at(i) = true;
  // [2, √b) の素数を順に
  for (long long i = 2; i*i < b; i++) {
    if (is_prime_small.at(i)) {  // 素数 i
      // [2, √b) の bool 表を作る
      for (long long j = 2*i; j*j < b; j += i) {
        is_prime_small.at(j) = false;
      }
      // [a, b) の bool 表を作る
      // (a+i-1)/i は a/i の切り上げ
      for (long long j = max(2LL, (a+i-1)/i) * i; j < b; j += i) {
        is_prime.at(j-a) = false;
      }
    }
  }
  long long ans = 0;
  for (auto v : is_prime) {
    if (v) ans++;
  }
  cout << ans << endl;
}