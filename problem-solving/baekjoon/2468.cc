// bg 2468 안전 영역
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n;
int max_height = 0;
int max_component = 1;
vector<vector<int>> board(101, vector<int> (101));

void DFS(int y, int x, vector<vector<bool>>& visited) {
    stack<pair<int, int>> st;
    visited[y][x] = 1;
    st.push({y, x});

    while(!st.empty()) {
        int cy = st.top().first;
        int cx = st.top().second;
        st.pop();

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny >= 0 && ny < n && nx >= 0 && nx < n && board[ny][nx] != 0 && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                st.push({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int a;
            cin >> a;
            if (a > max_height) {
                max_height = a;
            }
            board[i][j] = a;
        }
    }

    for (int h=1; h<=max_height; h++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] <= h) {
                    board[i][j] = 0;
                }
            }
        }
        int ret = 0;
        vector<vector<bool>> visited(n, vector<bool> (n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] != 0 && !visited[i][j]) {
                    ret++;
                    DFS(i, j, visited);
                }
            }
        }
        max_component = max(ret, max_component);
    }
    cout << max_component;
	return 0;
}