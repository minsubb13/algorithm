// bg 2562 최댓값
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int max_num = 0;
  int idx = 0;
  for (int i = 0; i < 9; i++) {
    int num;
    cin >> num;
    if (num > max_num) {
      idx = i;
      max_num = num;
    }
  }
  cout << max_num << "\n";
  cout << idx+1 << "\n";
  return 0;
}
