// bg 10807 개수세기

#include <bits/stdc++.h>

using namespace std;

int n, v;
vector<int> num(101);
int ret;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    num[i] = a;
  }

  cin >> v;

  for (int i = 0; i < n; i++) {
    if (num[i] == v) {
      ret++;
    }
  }
  cout << ret;
  return 0;
}

