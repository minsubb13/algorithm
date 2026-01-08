// bg 2493 탑
#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;

  stack<pair<int, int>> st;

  for (int i = 1; i <= n; i++) {
    int height;
    cin >> height;

    while (!st.empty() && st.top().first < height) {
      st.pop();
    }

    if (st.empty()) {
      cout << 0 << " ";
    } else {
      cout << st.top().second << " ";
    }

    st.push({height, i});
  }

  return 0;
}
