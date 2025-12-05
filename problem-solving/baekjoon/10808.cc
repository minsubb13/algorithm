// bg 10808 알파벳 개수
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<int> word(26, 0);

int main() {
  string s;
  cin >> s;

  for (char c : s) {
    int idx = c - 'a';
    word[idx]++;
  }

  for (auto c : word) {
    cout << c << " ";
  }

  return 0;
}
