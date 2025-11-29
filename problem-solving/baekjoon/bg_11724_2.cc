// bg 11724 연결 요소의 개수
// DFS - 재귀 & 인접 리스트(Adjacency List)
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;
vector<int> adj_list[1001];
vector<bool> visited(1001, 0);

void dfs (int u) {
    visited[u] = 1;
    for (int i=0; i<adj_list[u].size(); i++) {
        int next = adj_list[u][i];
        if (visited[next] == 0) {
            dfs(next);
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
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