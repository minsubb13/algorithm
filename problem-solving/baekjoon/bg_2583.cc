// bg 2583 영역구하기
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int m,n,k;
int component_num = 0;
int vertex_num = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<int>> area(101, vector<int>(101, 0));
vector<vector<bool>> visited(101, vector<bool>(101, 0));
vector<int> ret;

int DFS(int y, int x, int count) {
    stack<pair<int, int>> st;
    visited[y][x] = 1;
    st.push({y, x});

    while (!st.empty()) {
        int cy = st.top().first;
        int cx = st.top().second;
        st.pop();

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && area[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                count++;
                st.push({ny, nx});
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k; // x, y

    for (int input = 0; input < k; input++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // j, i

        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                area[i][j] = 1;
            }
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (area[i][j] == 0 && !visited[i][j]) {
                component_num++;
                int tmp = DFS(i, j, 1);
                ret.push_back(tmp);
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << component_num << '\n';
    for (auto i : ret) {
        cout << i << " ";
    }
    
	return 0;
}