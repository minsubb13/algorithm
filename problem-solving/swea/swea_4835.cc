// 누적합 구현
#include <iostream>
#include <algorithm>
using namespace std;

int num[100], psum[100];
int n, m;

int prefix_sum(int a, int b) {
    return (psum[b] - (a > 0 ? psum[a - 1] : 0));
}

int solve(int m) {
    int sum = 0;
    int min_n = 987654321, max_n = 0;  // 적절한 초기값 설정
    for (int i = 0; i <= n - m; i++) {  // '<='로 수정하여 마지막 구간도 포함
        sum = prefix_sum(i, i + m - 1);
        max_n = max(max_n, sum);
        min_n = min(min_n, sum);
    }
    return (max_n - min_n);
}

int main() {
    int tc;
    cin >> tc;
    for(int testcase = 0; testcase < tc; testcase++) {
        cin >> n >> m;
        psum[0] = 0;  // 누적합 배열 초기화
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            psum[i + 1] = psum[i] + num[i];
        }
        int result = solve(m);
        cout << "#" << testcase + 1 << " " << result << '\n';
    }
    return 0;
}