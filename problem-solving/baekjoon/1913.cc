// bg 1913 달팽이
#include <bits/stdc++.h>

using namespace std;

int n, num;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int answer_y, answer_x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> num;

  vector<vector<int>> matrix(n, vector<int>(n, 0));
  int y = 0;
  int x = 0;
  int d = 0;

  for (int i = n * n; i >= 1; i--) {
    matrix[y][x] = i;
    if (i == num) {
      answer_y = y + 1;
      answer_x = x + 1;
    }

    int ny = y + dy[d];
    int nx = x + dx[d];

    if (!(0 <= ny && ny < n &&
        0 <= nx && nx < n &&
        matrix[ny][nx] == 0)) {
      d = (d + 1) % 4;
      ny = y + dy[d];
      nx = x + dx[d];
    }
    y = ny;
    x = nx;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << '\n';
  }
  cout << answer_y << " " << answer_x;

  return 0;
}
