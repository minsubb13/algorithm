// bg 1475 방 번호
#include <bits/stdc++.h>

using namespace std;

vector<int> a(10);

int main() {
  int num;
  cin >> num;

  while (num > 0) {
    a[num%10]++;
    num = num/10;
  }

  int ret = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 9) {
      continue;
    }
    if (a[i] >= ret) {
      ret = a[i];
    }
  }
  ret = max(ret, (a[6]+a[9]+1) / 2);
  cout << ret << "\n";

  return 0;
}
