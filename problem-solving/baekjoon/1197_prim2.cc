// bg 1197 MST
// using Prim's algorithm, adjacency list
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
int result = 0;
// 인접 리스트 형태
vector<vector<pair<int,int>>> graph;  // {{u, v}, weight}
vector<bool> visited;

// {weight, {u, v}}
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void prim(int start) {
    pq.push({0, start});
    
    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(visited[node]) continue;
        
        visited[node] = true;
        result += weight;
        
        for(auto next : graph[node]) {
            int next_node = next.first;
            int next_weight = next.second;
            
            if(!visited[next_node]) {
                pq.push({next_weight, next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E;
    
    graph.resize(V + 1);
    visited.resize(V + 1);
    
    // 간선 정보 입력
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    prim(1);
    cout << result << '\n';
    
    return 0;
}