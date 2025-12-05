// bg 17070 파이프 옮기기 1
#include <iostream>
#include <vector>
using namespace std;

int n, result;
vector<vector<int>> board(17, vector<int>(17, 0));

void push_pipe(int row, int col, int state) {
    if (row == n - 1 && col == n - 1) {
        result++;
        return ;
    }

    if (state == 0) {
        // 가로
        if (col + 1 < n) {
            if (board[row][col + 1] == 0) {
                push_pipe(row, col + 1, 0);
            }
        }
        // 대각 이동 가능
        if (row + 1 < n && col + 1 < n) {
            if (board[row][col + 1] == 0 && board[row + 1][col + 1] == 0 && board[row + 1][col] == 0) {
                push_pipe(row + 1, col + 1, 1);
            }
        }
    }

    if (state == 1) {
        // 가로
        if (col + 1 < n) {
            if (board[row][col + 1] == 0) {
                push_pipe(row, col + 1, 0);
            }
        }
        // 대각 이동 가능
        if (row + 1 < n && col + 1 < n) {
            if (board[row][col + 1] == 0 && board[row + 1][col + 1] == 0 && board[row + 1][col] == 0) {
                push_pipe(row + 1, col + 1, 1);
            }
        }
        // 세로
        if (row + 1 < n) {
            if (board[row + 1][col] == 0) {
                push_pipe(row + 1, col, 2);
            }
        }
    }

    if (state == 2) {
        // 대각 이동 가능
        if (row + 1 < n && col + 1 < n) {
            if (board[row][col + 1] == 0 && board[row + 1][col + 1] == 0 && board[row + 1][col] == 0) {
                push_pipe(row + 1, col + 1, 1);
            }
        }
        // 세로
        if (row + 1 < n) {
            if (board[row + 1][col] == 0) {
                push_pipe(row + 1, col, 2);
            }
        }
    }
}

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
    
    push_pipe(0, 1, 0);

    cout << result << '\n';
	return 0;
}