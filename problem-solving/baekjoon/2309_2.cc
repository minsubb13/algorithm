// bg 2309 일곱난쟁이
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> a(10);
int sum_all;

int main() {
  for (int i = 0; i < 9; i++) {
    int num;
    cin >> num;
    a.push_back(num);
    sum_all += num;
  }
  sort(a.begin(), a.end());

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      int sum = a[i] + a[j];
      if (sum_all - sum == 100) {


}

