#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int n, m;
vector<bool> visited(1001);
stack<int> s;
vector<vector<int>> adj_mat(1001, vector<int>(1001, 0));

void DFS(int u) {
  s.push(u);
  visited[u] = 1;

  while(!s.empty()) {
    int current = s.top();
    s.pop();

    for (int next = 1; next <= n; next++) {
      if (adj_mat[current][next] == 1 && visited[next] != 1) {
        visited[next] = 1;
        s.push(next);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;

    adj_mat[a][b] = 1;
    adj_mat[b][a] = 1;
  }

  for (int i=1; i<=n; i++) {
    if (visited[i] == 0) {
      cnt++;
      DFS(i);
    }
  }
  cout << cnt;
  return 0;
}

