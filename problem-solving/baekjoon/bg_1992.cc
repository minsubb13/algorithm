// bg 1992 쿼드트리
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<char>> mat(65, vector<char>(65));

string quard(int y, int x, int n) {
    char first = mat[y][x];
    for (int i=y; i<y+n; i++) {
        for (int j=x; j<x+n; j++) {
            if (first != mat[i][j]) {
                string result = "(";
                result += quard(y, x, n/2);
                result += quard(y, x+(n/2), n/2);
                result += quard(y+(n/2), x, n/2);
                result += quard(y+(n/2), x+(n/2), n/2);
                result += ")";
                return result;
            }
        }
    }
    return string(1, first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << quard(0, 0, n) << '\n';
	
	return 0;
}