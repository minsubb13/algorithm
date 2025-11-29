// 2606 바이러스
#include <iostream>
#include <vector>

using namespace std;

int virus = 0;
int computer_num, route;
vector<vector<bool>> adj_matrix(101, vector<bool>(101, 0));
vector<bool> visited(101, 0);

void dfs(int n) {
    visited[n] = 1;
    virus++;
    for (int i=1; i<=computer_num; i++) {
        if (adj_matrix[n][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    cin >> computer_num >> route;

    for (int i=0; i<route; i++) {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }

    dfs(1);

    cout << virus - 1;

    
	return 0;
}