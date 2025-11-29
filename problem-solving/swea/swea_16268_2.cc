// 풍선팡2 _ padding 이용

#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int solve(vector<vector<int>> block) {
    int max = 0;
    int r = 0, c = 0;
    int direction = 0;
    int x = block[0].size()-2;
    int y = block.size()-2;

    for (int r=1; r<y+1; r++) {
        for (int c=1; c<x+1; c++) {
            int sum = 0;
            sum += block[r][c];

            for (direction = 0; direction<4; direction++) {
                int nextR = r + dr[direction];
                int nextC = c + dc[direction];

                sum += block[nextR][nextC];
            
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
        vector<vector<int>> block(n+2, vector<int>(m+2));

        for (int i=1; i<n+1; i++) {
            for (int j=1; j<m+1; j++) {
                cin >> block[i][j];
            }
        }

        int max = solve(block);

        cout << "#" << testcase+1 << " " << max << endl;

    }

    return 0;
}