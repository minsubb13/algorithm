// bg 1260 DFS and BFS - 3
// Using Adjacent List
// DFS using recursion and BFS using queue
#include <bits/stdc++.h>

using namespace std;

int n, m, v;

vector<int> answer_dfs;
vector<int> answer_bfs;

vector<int> adj_list[1001];
vector<int> visited_dfs(1001, 0);
vector<int> visited_bfs(1001, 0);

// Recursion DFS
void DFS(int v, int idx) {
  visited_dfs[v] = 1;
  answer_dfs.push_back(v);

  if (idx == n) {
    return ;
  }

  // Search next node
  for (int next = 0; next < adj_list[v].size(); next++) {
    int next_node = adj_list[v][next];
    if (visited_dfs[next_node] == 0) {
      DFS(next_node, idx + 1);
    }
  }
}

void BFS(int v) {
  queue<int> qu;
  visited_bfs[v] = 1;
  answer_bfs.push_back(v);
  qu.push(v);

  while (!qu.empty()) {
    int current = qu.front();
    qu.pop();

    for (int next = 0; next < adj_list[current].size(); next++) {
      int next_node = adj_list[current][next];
      if (visited_bfs[next_node] == 0) {
        visited_bfs[next_node] = 1;
        qu.push(next_node);
        answer_bfs.push_back(next_node);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m >> v;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  // If use adjacent list, must sort the list. This is because when there are multiple
  // vertices, the one with the smaller vertex number must be visited first.
  for (int i = 1; i <= n; i++) {
    sort(adj_list[i].begin(), adj_list[i].end());
  }

  DFS(v, 1);
  BFS(v);

  for (auto i : answer_dfs) {
    cout << i << " ";
  }
  cout << '\n';
  for (auto i : answer_bfs) {
    cout << i << " ";
  }

  return 0;
}
