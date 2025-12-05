// bg 11724 연결 요소의 개수
// DFS - 재귀 & 인접 행렬(Adjacency Matrix)
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;
vector<vector<bool>> adj_matrix (1001, vector<bool>(1001, 0));
vector<bool> visited(1001, 0);

void dfs (int u) {
    visited[u] = 1;
    for (int i=1; i<=n; i++) {
        if (adj_matrix[u][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }

    for (int i=1; i<=n; i++) {
        if (visited[i] == 0) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

	return 0;
}