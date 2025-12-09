// 2577 숫자의 개수
#include <bits/stdc++.h>

using namespace std;

vector<int> num(10);

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int res = a*b*c;

  for (int i = 0; i<10; i++) {
    num[i] = 0;
  }

  while (res > 0) {
    num[res % 10]++;
    res = res / 10;
  }

  for (int i = 0; i<10; i++) {
    cout << num[i] << "\n";
  }

  return 0;
}

