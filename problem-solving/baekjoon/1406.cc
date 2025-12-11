// bg 1406 에디터
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a;
  cin >> a;
  list<char> word;
  for (auto c : a) {
    word.push_back(c);
  }

  list<char>::iterator cursor = word.end();

  int num;
  cin >> num;
  while(num--){
    char op;
    cin >> op;

    if (op == 'L') {
      if (cursor != word.begin()) {
        cursor--;
      }
    } else if (op == 'D') {
      if (cursor != word.end()) {
        cursor++;
      }
    } else if (op == 'B') {
      if (cursor != word.begin()) {
        cursor--;
        cursor = word.erase(cursor);
      }
    } else {
      char c;
      cin >> c;
      word.insert(cursor, c);
    }
  }
  for (auto i : word) {
    cout << i;
  }
  return 0;
}
