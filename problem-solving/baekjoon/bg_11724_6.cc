// bg 11724 연결 요소의 개수
// BFS - queue & adjacency matrix
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
vector<int> adj_list[1001];
vector<bool> visited(1001, 0);
queue<int> q;

void bfs(int u) {
    visited[u] = true;
    q.push(u);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj_list[current]) {
            if (!visited[next]) {
                visited[current] = true;
                q.push(next);
            }
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
            bfs(i);
        }
    }
    cout << cnt;

	return 0;
}