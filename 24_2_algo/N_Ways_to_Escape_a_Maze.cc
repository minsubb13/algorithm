#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int row, col;
int result = 0;
vector<vector<int>> maze(21, vector<int>(21));
vector<vector<int>> visited(21, vector<int>(21));

void DFS(int y, int x) {
    if (y == row - 1 && x == col - 1) {
        result++;
        return;
    }

    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < row && nx >= 0 && nx < col && maze[ny][nx] == 0 && visited[ny][nx] == 0) {
            DFS(ny, nx);
        }
    }
    visited[y][x] = 0; // 백트레킹
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            char a;
            cin >> a;
            maze[i][j] = a - '0';
        }
    }

    DFS(0, 0);
    cout << result << '\n';

    return 0;
}