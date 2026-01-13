// bg 1260 DFS와 BFS
#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<int> answer_dfs;
vector<int> answer_bfs;

vector<vector<int>> mat(1001, vector<int>(1001, 0));
vector<int> visited_dfs(1001, 0);
vector<int> visited_bfs(1001, 0);

void DFS(int v) {
  stack<int> st;
  visited_dfs[v] = 1;
  answer_dfs.push_back(v);
  st.push(v);

  while (!st.empty()) {
    int current = st.top();
    st.pop();

    if (visited_dfs[current] == 0) {
      answer_dfs.push_back(current);
      visited_dfs[current] = 1;
    }

    for (int next = n; next >= 0; next--) {
      if (visited_dfs[next] == 0 && mat[current][next] == 1) {
        st.push(next);
      }
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

    for (int next = 1; next <= n; next++) {
      if (visited_bfs[next] == 0 && mat[current][next] == 1) {
        visited_bfs[next] = 1;
        answer_bfs.push_back(next);
        qu.push(next);
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

    mat[a][b] = 1;
    mat[b][a] = 1;
  }

  DFS(v);
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
