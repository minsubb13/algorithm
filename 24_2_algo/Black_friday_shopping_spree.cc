#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> shop(10004, -1);
vector<vector<int>> dp(10004, vector<int>(2, -1)); // dp[10004][2]

// pos : 현재 위치, flag : 이전 단계에서 연속적으로 가게를 방문했을 경우 1로 설정 (e.g. 1 -> 2)
// flag가 1인 경우 다시 연달아서 가게를 이동할 수 없음 (1 -> 2 -> 3 불가능)
int moving(int pos, int flag) {
    // base case
    if (pos > n) return -1e9;
    if (pos == n) return shop[pos];

    // memoization
    int& ret = dp[pos][flag];
    if (ret != -1) return ret;

    // logic
    int items = shop[pos];
    if (flag == 1) { // 연속 이동이 있었던 경우, 2칸 이동할 수 밖에 없음
        ret = moving(pos + 2, 0) + items;
    }
    else { // 연속적인 이동이 없는 경우
        ret = max(moving(pos + 1, 1), moving(pos + 2, 0)) + items;
    }

    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> shop[i];
    }
    int result = moving(1, 0);
    cout << result << '\n';

	return 0;
}