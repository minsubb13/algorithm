// 15552 빠른 A+B
#include <iostream>

using namespace std;

int T, a, b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> a >> b;
    cout << a + b << '\n';
  }

  return 0;
}
