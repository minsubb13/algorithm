// bg 7576 토마토
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int n,m;
int num_0 = 0, num_1 = 0;
int day = 0;
vector<vector<int>> mat(1001, vector<int>(1001));
vector<vector<int>> visited(1001, vector<int>(1001));
queue<pair<int, int>> starting_point;
queue<pair<int, int>> q;

void BFS(int num_1) {
    for (int i=0; i<num_1; i++) {
        int sy = starting_point.front().first;
        int sx = starting_point.front().second;
        starting_point.pop();
        visited[sy][sx] = 1;
        q.push({sy, sx});
    }

    while (q.size()) {
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = current_y + dy[i];
            int nx = current_x + dx[i];
            
            if (ny > 0 && ny <= n && nx > 0 && nx <= m) {
                if (mat[ny][nx] == 0 && visited[ny][nx] == 0) {
                    visited[ny][nx] = visited[current_y][current_x] + 1;
                    num_0--;
                    day = max(day, visited[ny][nx]);
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int a;
            cin >> a;
            if (a == 1) { // 입력받을 때 1의 개수와 좌표를 기록
                num_1++;
                starting_point.push(pair(i,j));
            }
            if (a == 0) num_0++;
            mat[i][j] = a;
        }
    }

    BFS(num_1);

    if (num_0 == 0) {
        if (day > 0) cout << day-1;
        else cout << day;
    } else {
        cout << -1;
    }
	
	return 0;
}