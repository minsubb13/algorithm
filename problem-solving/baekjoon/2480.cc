// bg 2480 주사위 세개
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) {
    cout << 10000 + (a*1000);
  }
  if (a == b && b != c) {
    cout << a*100 + 1000;
  } else if (b == c && a != c) {
    cout << b*100 + 1000;
  } else if (a == c && b != c) {
    cout << a*100 + 1000;
  }
  if (a != b && b != c && a != c) {
    int m = max({a, b, c});
    cout << m*100;
  }
  return 0;
}
