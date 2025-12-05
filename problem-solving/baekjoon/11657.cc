// bg 11657 타임머신
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

int V, E;
int inf = 987654321;
vector<Edge> edges;
vector<long long> dist;

bool bellman_ford(int start) {
    dist[start] = 0;

    for (int i = 0; i < V; i++) {
        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;

            if (dist[u] != inf && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (i == V - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin >> V >> E;
    edges.resize(E + 1);
    dist.resize(V + 1, inf);

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    int result = bellman_ford(1);
    if (result) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= V; i++) {
            if (dist[i] == inf) {
                cout << -1 << '\n';
            }
            else {
                cout << dist[i] << '\n';
            }
        }
    }

	return 0;
}