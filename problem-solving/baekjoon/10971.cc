// bg 10971 외판원 순회2
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int min_cost = 987654321;
vector<vector<int>> adj (11, vector<int> (11));
vector<bool> visited(11);

// current : 현재 노드, count : 방문한 정점 카운트, cost : 지금까지의 cost
void DFS(int current, int count, int cost) {
    if (count == n) { // 모든 노드를 방문
        if (adj[current][1] != 0) { // last_node에서 1번으로 돌아갈 수 있어?
            min_cost = min(min_cost, cost += adj[current][1]);
        }
        return ;
    }

    for (int next = 1; next <= n; next++) {
        if (adj[current][next] != 0 && !visited[next]) {
            visited[next] = 1;
            DFS(next, count+1, cost + adj[current][next]);
            visited[next] = 0;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int a;
            cin >> a;
            adj[i][j] = a;
        }
    }

    visited[1] = 1;
    DFS(1, 1, 0);

    cout << min_cost;
	return 0;
}