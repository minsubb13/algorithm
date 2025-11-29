// bg 1197 최소 스패닝 트리 MST
// Using Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, weight;
vector<int> parent;
vector<int> byrank;

struct Edge {
    int x;
    int y;
    int weight;
};

bool compare_function(const Edge& x, const Edge& y) {
    return x.weight < y.weight;
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y) return ;

    if (byrank[root_x] > byrank[root_y]) {
        parent[root_y] = root_x;
    }
    else if (byrank[root_x] < byrank[root_y]) {
        parent[root_x] = root_y;
    }
    else {
        parent[root_y] = root_x;
        byrank[root_x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;
    vector<Edge> edge;
    
    parent.resize(V + 1);
    byrank.resize(V + 1, 0);

    for (int i=1; i<=V; i++) {
        parent[i] = i;
    }

    for (int i=1; i<=E; i++) {
        int x, y, weight;
        cin >> x >> y >> weight;
        edge.push_back({x, y, weight});
    }

    sort(edge.begin(), edge.end(), compare_function);

    int mst_weight = 0;
    int count = 0;
    for (int i=0; i<E; i++) {
        if (find(edge[i].x) != find(edge[i].y)) {
            union_sets(edge[i].x, edge[i].y);
            mst_weight += edge[i].weight;
            count++;
        }
        
        if (count == V - 1) {
            break;
        }
    }

    cout << mst_weight << '\n';
	
	return 0;
}