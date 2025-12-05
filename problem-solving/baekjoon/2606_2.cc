// bg 2606 바이러스
// BFS - queue & adjacency list
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int virus = 0;
vector<int> adj_list[101];
bool visited[101];
queue<int> q;

void BFS(int u) {
    visited[u] = 1;
    q.push(u);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj_list[current]) {
            if (!visited[next]) {
                visited[next] = 1;
                virus++;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    BFS(1);
    cout << virus;

	
	return 0;
}
/*
7
6
1 2
2 3
1 5
5 2
5 6
4 7
*/