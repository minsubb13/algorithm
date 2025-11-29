// bg 17069 파이프 옮기기 2
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board(33, vector<int>(33, 0));
vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(33, vector<long long>(33)));

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            board[i][j] = a;
        }
    }

    dp[0][0][1] = 1;
    for (int i = 2; i < n; i++) {
        if (board[0][i] == 0) {
            dp[0][0][i] = dp[0][0][i - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (board[i][j] == 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0) {
                dp[2][i][j] = dp[2][i - 1][j - 1] + dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1];
            }
            if (board[i][j] == 0) {
                dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
                dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
            }
        }
    }

    long long result = dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1];

    cout << result << '\n';

	return 0;
}