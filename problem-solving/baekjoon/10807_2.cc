// bg 10807 개수 세기 Hash
#include <bits/stdc++.h>

using namespace std;

int n, v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_map<int, int> um;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    um[num]++;
  }
  cin >> v;
  if (um.find(v) == um.end()) {
    cout << 0;
  } else {
    cout << um[v];
  }
  return 0;
}
