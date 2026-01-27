// bg 1806 부분합
#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  vector<int> partial_sum(n + 1);

  partial_sum[0] = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    partial_sum[i + 1] = partial_sum[i] + num;
  }

  int answer = n + 1;
  int en = 0;
  for (int st = 0; st < n; st++) {
    while (en <= n && partial_sum[en] - partial_sum[st] < s) {
      en++;
    }
    if (en > n) {
      break;
    }
    answer = min(answer, en - st);
  }

  if (answer == n + 1) {
    cout << 0;
  } else {
    cout << answer;
  }

  return 0;
}
