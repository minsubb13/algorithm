// 2490 윷놀이
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int t = 0; t < 3; t++) {
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    int all = arr[0] + arr[1] + arr[2] + arr[3];
    if (all == 0) {
      cout << "D\n";
    } else if (all == 3) {
      cout << "A\n";
    } else if (all == 2) {
      cout << "B\n";
    } else if (all == 1) {
      cout << "C\n";
    } else {
      cout << "E\n";
    }
  }
  return 0;
}
