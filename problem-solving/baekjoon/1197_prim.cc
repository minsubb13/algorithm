// bg 1197 최소 스패닝 트리 MST
// Using Prim's algorithm, adjacency list
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, weight;
int result = 0;

vector<vector<int>> graph; // 인접 행렬로 구현
vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, vertex

void Prim(int start) {
    visited[start] = 1;
    pq.push({0, start});

    for (int next = 1; next <= V; next++) {
        if (graph[start][next] != 0) {
            pq.push({graph[start][next], next});
        }
    }

    while (!pq.empty()) {
        int current_weight = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node]) continue;

        visited[current_node] = 1;
        result += current_weight;

        for (int next = 1; next <= V; next++) {
            if (graph[current_node][next] != 0 && !visited[next]) {

                pq.push({graph[current_node][next], next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    graph.resize(V + 1, vector<int> (V + 1));
    visited.resize(V + 1, 0);
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    Prim(1);

    cout << result << '\n';
	return 0;
}