#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b;
  int ret = 0;
  
  cin >> a >> b;
  vector<vector<int>> mat(a, vector<int> (b));
  
  for (int i=0; i<a; i++) {
	for (int j=0; j<b; j++) {
	  cin >> mat[i][j];
      ret += mat[i][j];
    }
  }
  cout << ret;
  return 0;
}