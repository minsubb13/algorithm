// bg 9663 N-Queen
#include <iostream>
#include <vector>

using namespace std;

int n;
int result = 0;

bool canMove(vector<vector<bool>>& board, int row, int col) {
    // 세로
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // 좌상단 대각선
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // 우상단 대각선
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void nqueen(vector<vector<bool>>& board, int row) {
    if (row == n) {
        result++;
        return ;
    }

    for (int i = 0; i < n; i++) {
        board[row][i] = 1;
        if (canMove(board, row, i) == true) {
            nqueen(board, row + 1);
        }
        board[row][i] = 0; // backtracking
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, 0));

    nqueen(board, 0);
    cout << result << '\n';
	
	return 0;
}