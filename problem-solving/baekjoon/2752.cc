// bg 2752 세수정렬
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;

  int max = max({a, b, c});
  int min = min({a, b, c});

  int mid = a + b + c - max - min;

  cout << min << mid << max;
  return 0;
}
