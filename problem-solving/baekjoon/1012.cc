// bg 1012 유기농 배추
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m, num;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void DFS(int y, int x, vector<vector<int>>& land, vector<vector<int>>& visited) {
    stack<pair<int,int>> s;
    visited[y][x] = 1;
    s.push({y,x});

    while (!s.empty()) {
        int cy = s.top().first;
        int cx = s.top().second;
        s.pop();

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && land[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                s.push({ny, nx});
            }
        }
    }
}

int main() {
    int testcase;
    cin >> testcase;
    for (int tc=0; tc<testcase; tc++) {
        cin >> m >> n >> num;

        vector<vector<int>> land(51, vector<int>(51, 0));
        vector<vector<int>> visited(51, vector<int>(51, 0));
        int cnt = 0;

        for (int i=0; i<num; i++) {
            int x, y;
            cin >> x >> y;
            land[y][x] = 1;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (land[i][j] == 1 && visited[i][j] == 0) {
                    cnt++;
                    DFS(i, j, land, visited);
                }
            }
        }
        cout << cnt << '\n';
    }
	return 0;
}