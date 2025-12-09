// bg 1920 수 찾기
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a(100001);

int binary_search(int target, int left, int right) {
  if (left > right) {
    return 0;
  }
  int mid = (left + right) / 2;

  if (target == a[mid]) {
    return 1;
  }

  if (a[mid] < target) {
    return binary_search(target, mid + 1, right);
  } else {
    return binary_search(target, left, mid - 1);
  }
}


int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.begin() + n);

  cin >> m;
  for (int i = 0; i < m; i++) {
    int target;
    cin >> target;

    int ret = binary_search(target, 0, n - 1);
    cout << ret << "\n";
  }
  return 0;
}

