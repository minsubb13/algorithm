// bg 2230 수 고르기 (이진탐색)
#include <bits/stdc++.h>

using namespace std;

long long n;
long long m;
long long ret = 0x7fffffff;

vector<long long> a(100001);

int lower_bound(long long target, int st, int en) {
  int res = -1;

  while (st <= en) {
    int mid = (st + en) / 2;

    if (a[mid] >= target) {
      res = mid;
      en = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.begin() + n);

  for (int i = 0; i < n; i++) {
    long long target = a[i]+m;

    int j = lower_bound(target, i, n-1);
    if (a[j]-a[i] < ret) {
      ret = a[j]-a[i];
    }
  }

  cout << ret;
  return 0;
}

