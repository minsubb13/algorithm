// bg 15683 감시
#include <bits/stdc++.h>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct CCTV {
  int type;
  int y;
  int x;
};

int n, m;
int answer = 987654321;
int count_cctv;
vector<CCTV> cctv;

void draw(vector<vector<int>>& map, int y, int x, int d) {
  while (true) {
    y = y + dy[d];
    x = x + dx[d];

    if (y < 0 || y >= n || x < 0 || x >= m) {
      break;
    }
    if (map[y][x] == 6) {
      break;
    }
    if (map[y][x] == 0) {
      map[y][x] = 7;
    }
  }
}

int CountBlindSpot(vector<vector<int>>& map) {
  int count_blind_spot = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        count_blind_spot++;
      }
    }
  }

  return count_blind_spot;
}

void dfs(int idx, vector<vector<int>>& map) {
  if (idx == count_cctv) {
    int blind_spot = CountBlindSpot(map);
    answer = min(answer, blind_spot);
    return ;
  }

  int type = cctv[idx].type;
  int y = cctv[idx].y;
  int x = cctv[idx].x;

  // 현재 cctv에 가능한 방향 시도
  if (type == 1) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> new_map = map;
      draw(new_map, y, x, i);
      dfs(idx + 1, new_map);
    }
  } else if (type == 2) {
    for (int i = 0; i < 2; i++) {
      vector<vector<int>> new_map = map;
      draw(new_map, y, x, i);
      draw(new_map, y, x, i + 2);
      dfs(idx + 1, new_map);
    }
  } else if (type == 3) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> new_map = map;
      draw(new_map, y, x, i % 4);
      draw(new_map, y, x, (i + 1) % 4);
      dfs(idx + 1, new_map);
    }
  } else if (type == 4) {
    for (int i = 0; i < 4; i++) {
      vector<vector<int>> new_map = map;
      draw(new_map, y, x, i % 4);
      draw(new_map, y, x, (i + 1) % 4);
      draw(new_map, y, x, (i + 2) % 4);
      dfs(idx + 1, new_map);
    }
  } else { // type == 5
    vector<vector<int>> new_map = map;
    draw(new_map, y, x, 0);
    draw(new_map, y, x, 1);
    draw(new_map, y, x, 2);
    draw(new_map, y, x, 3);
    dfs(idx + 1, new_map);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m;
  vector<vector<int>> map(n, vector<int> (m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      map[i][j] = num;

      if (num > 0 && num < 6) { // cctv 파악
        cctv.push_back({num, i, j});
        count_cctv++;
      }
    }
  }

  dfs(0, map);

  cout << answer << '\n';

  return 0;
}

