#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vec(10, vector<int>(10));

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}

int main() {
  vec = {{80,20}, {80, 30}, {70, 20}, {30, 10}};

   sort(vec.begin(), vec.end(), compare);

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i][0] << ", " << vec[i][1];
    cout << "\n";
  }
  return 0;
}
