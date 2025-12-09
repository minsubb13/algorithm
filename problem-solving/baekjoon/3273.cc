// bg 3273 SumX

#include <bits/stdc++.h>

using namespace std;

vector<int> s(1000001);
vector<int> dict(2000001);
int n, x, ret;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    s[i] = num;
    dict[num] = 1;
  }

  cin >> x;

  for (int i = 1; i <= n; i++) {
    if((x - s[i] > 0) && (dict[x - s[i]] == 1)) {
      ret++;
    }
  }
  cout << ret / 2;
  return 0;
}
