// 2855 나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
int trees[MAX_N];
int n, m;

long long caculate_sum(int height) {
    long long sum = 0;
    for (int i=0; i<n; i++) {
        if (trees[i] > height) {
            sum += (trees[i] - height);
        }
    }
    return sum;
}

int binary_search(int left, int right) {
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = caculate_sum(mid);

        if (sum == m) { // 자른 나무의 합이 m과 같을 때,
            return mid;
        }
        else if (sum > m) { // 자른 나무의 합이 m보다 클때, sum을 줄여야함 -> left를 이동
            result = mid; // 최댓값을 구하는 것이니 result 변수 필요
            left = mid + 1; // 이미 mid는 검사했으므로 mid를 제외 -> 효율성 극대화
        }
        else { // 자른 나무의 합이 m보다 작을 때, 나무를 더 잘라야함.
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int right = 0;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        right = max(right, trees[i]);
    }

    cout << binary_search(0, right) << '\n';

	return 0;
}