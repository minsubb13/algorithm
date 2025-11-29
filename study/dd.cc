#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<vector<char>> mat(5, vector<char>(5));
	string word = "";
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            char a;
            cin >> a;
            mat[i][j] = a;
            word.push_back(mat[i][j]);
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
    cout << word << '\n';
    cout << word.size() << '\n';
    


	return 0;
}