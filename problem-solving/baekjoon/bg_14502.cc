// bg 14502 연구소
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int wall_size;
int max_safety_area = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int>> lab(8, vector<int>(8));
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;

void DFS(int y, int x, vector<vector<bool>>& visited) {
    visited[y][x] = 1;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && lab[ny][nx] != 1 && !visited[ny][nx]) {
            visited[ny][nx] = 1;
            DFS(ny, nx, visited);
        }
    }
}

int solve() {
    vector<vector<bool>> visited(8, vector<bool>(8,0));
    for (auto s : virus) {
        if (!visited[s.first][s.second]) {
            DFS(s.first, s.second, visited);
        }
    }
    int cnt_0 = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (lab[i][j] == 0 && !visited[i][j]) {
                cnt_0++;
            }
        }
    }
    return cnt_0;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int a;
            cin >> a;
            if (a == 0) { wall.push_back({i, j}); }
            if (a == 2) { virus.push_back({i, j}); }
            lab[i][j] = a;
        }
    }

    wall_size = wall.size();
    int cnt_0 = 0;
    for (int i=0; i<wall_size; i++) {
        for (int j=i+1; j<wall_size; j++) {
            for (int k=j+1; k<wall_size; k++) {
                lab[wall[i].first][wall[i].second] = 1;
                lab[wall[j].first][wall[j].second] = 1;
                lab[wall[k].first][wall[k].second] = 1;
                cnt_0 = solve();
                lab[wall[i].first][wall[i].second] = 0;
                lab[wall[j].first][wall[j].second] = 0;
                lab[wall[k].first][wall[k].second] = 0;
                max_safety_area = max(max_safety_area, cnt_0);
            }
        }
    }
	cout << max_safety_area;
	return 0;
}