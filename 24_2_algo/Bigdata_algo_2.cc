#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, T;
int max_yield = 0;
int minimum_costs = INT_MAX;
int path_length = 0;

vector<vector<int>> travel_costs;
vector<int> visited;
vector<int> costs;
vector<int> productions;
vector<int> path;
vector<int> best_path;

void DFS(int current, int total_costs, int yield, int length_of_path) {
    // 현재 노드를 방문 처리
    visited[current] = 1;

    // 탐색 중단 조건: 이미 최소 비용을 초과한 경우
    if (total_costs >= minimum_costs) {
        visited[current] = 0;  // backtrack
        return;
    }

    // 목표 yield를 달성했거나 초과한 경우
    if (yield >= T) {
        // 최소 비용인 경우 업데이트
        if (total_costs < minimum_costs) {
            max_yield = yield;
            minimum_costs = total_costs;
            path_length = length_of_path;
            best_path = path;
        }
        // 비용이 같을 경우, 경로가 더 긴 경우 업데이트
        else if (total_costs == minimum_costs && length_of_path > path_length) {
            max_yield = yield;
            path_length = length_of_path;
            best_path = path;
        }
        visited[current] = 0;  // backtrack
        return;
    }

    // 다음 노드 탐색
    for (int next = 0; next < N; next++) {
        if (travel_costs[current][next] != 0 && !visited[next]) {
            path.push_back(next);
            DFS(next, 
                total_costs + travel_costs[current][next] + costs[next], 
                yield + productions[next], 
                length_of_path + 1);
            path.pop_back();
        }
    }

    // backtrack시 방문 표시 제거
    visited[current] = 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    
    // 벡터 크기 조정
    travel_costs.resize(N, vector<int>(N));
    productions.resize(N);
    costs.resize(N);
    
    visited.resize(N, 0);  // 0으로 초기화

    // 생산량 입력
    for (int i = 0; i < N; i++) {
        cin >> productions[i];
    }
    
    // 비용 입력
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }

    // 이동 비용 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> travel_costs[i][j];
        }
    }

    // 각 시작점에서 DFS 수행
    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), 0);
        path.clear();
        path.push_back(i);
        
        DFS(i, costs[i], productions[i], 1);
    }
    
    if (max_yield < T) {
        cout << "Target yield not achievable\n";
    } else {
        cout << "Minimum costs: " << minimum_costs << '\n';
        cout << "Path: [";
        for (size_t i = 0; i < best_path.size(); i++) {
            cout << best_path[i];
            if (i < best_path.size() - 1) cout << ", ";
        }
        cout << "]\n";
        cout << "Path length: " << path_length << '\n';
    }

    return 0;
}