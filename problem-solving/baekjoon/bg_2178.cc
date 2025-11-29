// bg 2178 미로 탐색
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maze[101][101];
// 우-하-좌-상
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int visited[101][101];
queue<pair<int, int>> q;

void BFS(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});

    while (!q.empty()) {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            if (ny > 0 && ny <= n && nx > 0 && nx <= m && maze[ny][nx] == 1) {
                if (visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[current_y][current_x] + 1;
                    q.push({ny, nx});
                }
            }            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            maze[i][j] = c - '0';
        }
    }
    BFS(1,1);
    
    cout << visited[n][m];
	
	return 0;
}