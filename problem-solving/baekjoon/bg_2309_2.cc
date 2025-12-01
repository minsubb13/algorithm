// bg 2309 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a(9);
int all_sum;

int main() {
  for (int i = 0; i < 9; i++) {
    int num;
    cin >> num;
    a[i] = num;
    all_sum += num;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      int spy = a[i] + a[j];
      if (all_sum - spy == 100) {
        a.erase(a.begin() + j);
        a.erase(a.begin() + i);
        sort(a.begin(), a.end());

        for (int i = 0; i < 7; i++) {
          cout << a[i] << "\n";
        }
        return 0;
      }
    }
  }

  return 0;
}
