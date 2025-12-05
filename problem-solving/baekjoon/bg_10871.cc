#include <iostream>

using namespace std;

int N, X;

int main() {
  cin >> N >> X;

  while(N--) {
    int num;
    cin >> num;
    if (num < X) {
      cout << num << " ";
    }
  }


  return 0;
}

