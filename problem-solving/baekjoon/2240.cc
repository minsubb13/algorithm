// bg 2240 자두나무
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, m;
// [1004][2][31]
vector<vector<vector<int>>> dp(1004, vector<vector<int>>(2, vector<int>(31, -1)));
vector<int> location(1004);

int moving(int idx, int pos, int cnt) {
    // 기저 사례
    if (cnt < 0) return -1e9;
    if (idx == t) return 0;

    // 메모이제이션, 현재 상황을 저장
    int& ret = dp[idx][pos][cnt];
    if (ret != -1) return ret;

    // 로직
    int plum = (pos == (location[idx] - 1)) ? 1 : 0;
    ret = max(moving(idx + 1, pos, cnt), moving(idx + 1, pos^1, cnt - 1)) + plum;

    return ret;
}

int main() {
    cin >> t >> m;

    for (int i=0; i<t; i++) {
        cin >> location[i];
    }

    int result = max(moving(0, 0, m), moving(0, 1, m-1));
    cout << result << '\n';

	return 0;
}