// bg 3184 양
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int r, c;
int sheep = 0, wolf = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<char>> pasture (251, vector<char> (251));
vector<vector<bool>> visited (251, vector<bool> (251));
stack<pair<int,int>> s;

void DFS(int y, int x) {
    int oo = 0;
    int vv = 0;
    visited[y][x] = 1;
    s.push({y, x});

    while (!s.empty()) {
        int cy = s.top().first;
        int cx = s.top().second;
        s.pop();
        
        if (pasture[cy][cx] == 'o') oo++;
        if (pasture[cy][cx] == 'v') vv++;

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < r && nx >= 0 && nx < c && pasture[ny][nx] != '#' && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                s.push({ny, nx});
            }
        }
    }
    if (oo > vv) sheep += oo;
    else wolf += vv;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> r >> c;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            char a;
            cin >> a;
            pasture[i][j] = a;
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (pasture[i][j] != '#' && !visited[i][j]) {
                DFS(i, j);
            }
        }
    }

    cout << sheep << " " << wolf;
    
	return 0;
}
/*
6 6
...#..
.##v#.
#v.#.#
#.o#.#
.###.#
...###
*/