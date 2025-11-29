// 달팽이 숫자

#include <iostream>
#include <vector>

using namespace std;

// 우 - 하 - 좌 - 상
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

void solve(vector<vector<int>>& snail) {
    int r = 0;
    int c = 0;
    int direction = 0;
    int num = snail[0].size();

    for (int i=1; i<(num*num)+1; i++) {
        snail[r][c] = i;

        int nextR = r + dr[direction];
        int nextC = c + dc[direction];

        if (nextR >= num || nextR < 0 || nextC >= num || nextC < 0 || snail[nextR][nextC] != 0) {
            direction = (direction+1) % 4;
            nextR = r + dr[direction];
            nextC = c + dc[direction];
        }

        r = nextR;
        c = nextC;
    }

}

int main() {
    int tc;
    cin >> tc;

    for (int testcase=0; testcase < tc; testcase++) {
        int n;
        cin >> n;

        vector<vector<int>> snail(n, vector<int>(n, 0));

        solve(snail);

        cout << "#" << testcase+1 << endl;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << snail[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}