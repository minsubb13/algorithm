// 2752 세수정렬
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  int mmax, mmin, mmid;
  cin >> a >> b >> c;

  mmax = max({a, b, c});
  mmin = min({a, b, c});
  mmid = a + b + c - mmax - mmin;

  cout << mmin << " "  << mmid << " " << mmax;


  return 0;
}

