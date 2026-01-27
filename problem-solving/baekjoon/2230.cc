// bg 2230 수 고르기
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int answer = 1987654321;
  int en = 0;
  for (int st = 0; st < a.size(); st++) {
    while (a[en] - a[st] < m && en < a.size()) {
      en++;
    }
    if (en == n) {
      break;
    }
    answer = min(answer, a[en] - a[st]);
  }

  cout << answer;
  return 0;
}

