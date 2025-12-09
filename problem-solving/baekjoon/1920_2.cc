// bg 1920 수 찾기 while
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a(100001);

int binary_search(int target, int left, int right) {
  int ret = 0;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (target == a[mid]) {
      ret = 1;
      return ret;
    } else if (target > a[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);

  cin >> m;
  for (int i = 0; i < m; i++) {
    int target;
    cin >> target;

    int ret = binary_search(target, 0, n-1);
    cout << ret << "\n";
  }
  return 0;
}

