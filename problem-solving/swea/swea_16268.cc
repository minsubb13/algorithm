// 풍선팡2

#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int solve(vector<vector<int>> block) {
    int max = 0;
    int r = 0, c = 0;
    int direction = 0;

    for (int r=0; r<block.size(); r++) {
        for (int c=0; c<block[0].size(); c++) {
            int sum = 0;
            sum += block[r][c];

            for (direction = 0; direction<4; direction++) {
                int nextR = r + dr[direction];
                int nextC = c + dc[direction];

                if (nextR >= 0 && nextR < block.size() && nextC >= 0 && nextC < block[0].size()) {
                    sum += block[nextR][nextC];
                }
                if (max < sum) {
                    max = sum;
                }
            }
        }
    }
    return max;
}

int main() {
    int tc;
    cin >> tc;

    for (int testcase=0; testcase<tc; testcase++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> block(n, vector<int>(m));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> block[i][j];
            }
        }

        int max = solve(block);

        cout << "#" << testcase+1 << " " << max << endl;

    }

    return 0;
}