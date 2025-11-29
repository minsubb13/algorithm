#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
const int INF = 987654321;

vector<vector<int>> travel_costs;
vector<int> costs;
vector<int> productions;

vector<vector<int>> dp;
vector<bool> visited;

vector<int> current_path;
vector<int> best_path;

int min_total_cost = INF;
int max_path_length = 0;

void travel(int current, int yield, int total_cost, int path_length) {
    if (yield == T) {
        if (min_total_cost == total_cost) {
            if (path_length > max_path_length) {
                min_total_cost = total_cost;
                max_path_length = path_length;
                best_path = current_path;
            }
        }
        else {
            min_total_cost = total_cost;
            max_path_length = path_length;
            best_path = current_path;
        }
        return ;
    }
    else if (yield > T) {
        return ;
    }

    if (dp[current][yield] != -1 && dp[current][yield] < total_cost) {
        return ;
    }
    dp[current][yield] = total_cost;

    for (int next = 0; next < N; next++) {
        if (!visited[next]) {
            int current_yield = yield + productions[next];
            int current_costs = total_cost + costs[next] + travel_costs[current][next];
            if (min_total_cost == INF || current_costs <= min_total_cost) {
                visited[next] = true;
                current_path.push_back(next);

                travel(next, current_yield, current_costs, path_length + 1);

                visited[next] = false;
                current_path.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> T;
    
    // 벡터 초기화
    travel_costs.resize(N, vector<int>(N));
    costs.resize(N);
    productions.resize(N);

    dp.resize(N, vector<int>(T + 1, -1));
    visited.resize(N, false);

    // 입력 처리
    for (int i = 0; i < N; i++) {
        cin >> productions[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> travel_costs[i][j];
        }
    }
    
    for (int start = 0; start < N; start++) {
        for (int i = 0; i < N; i++) {
            fill(dp[i].begin(), dp[i].end(), -1);
        }
        visited[start] = true;
        current_path.push_back(start);

        travel(start, productions[start], costs[start], 1);

        visited[start] = false;
        current_path.pop_back();
    }

    cout << "Minimum cost: " << min_total_cost << '\n';
    cout << "Path: ";
    for (int node : best_path) {
        cout << node << ' ';  // 1-based indexing
    }
    cout << '\n';
    cout << "Path length: " << max_path_length;
    
    return 0;
}