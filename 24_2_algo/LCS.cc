#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;
string X;
string Y;
vector<vector<int>> b;
vector<vector<int>> c;

void LCS_LENGTH(string X, string Y) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 0; // 왼쪽 위 대각선
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1; // 위 화살표
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2; // 왼쪽 화살표
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;
    cin >> Y;
    m = X.length();
    n = Y.length();
    b.resize(m + 1, vector<int>(n + 1, 0));
    c.resize(m + 1, vector<int>(n + 1, 0));

    LCS_LENGTH(X, Y);
    cout << c[m][n] << '\n';

	return 0;
}