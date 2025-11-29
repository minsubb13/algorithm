// swea 2001 파리퇴치
#include <iostream>
#include <vector>

using namespace std;

int tc;
int solve (int n, int m, int x, int y, vector<vector<int>>& board) {
    int ret = 0;
    for (int i=x; i<x+m; i++) {
        for (int j=y; j<y+m; j++) {
            ret += board[i][j];
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> tc;
    for (int testcase = 0; testcase < tc; testcase++) {
        int n, m;
        int max_n = 0;
        int sum = 0;
        cin >> n >> m;
        vector<vector<int>> board(n, vector<int>(n));

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int a;
                cin >> a;
                board[i][j] = a;
            }
        }

        for (int i=0; i<n-m+1; i++) {
            for (int j=0; j<n-m+1; j++) {
                sum = solve(n,m,i,j,board);
                if (sum > max_n) {
                    max_n = sum;
                }
            }
        }
        cout << '#' << testcase+1 << " " << max_n << '\n';
    }
	return 0;
}