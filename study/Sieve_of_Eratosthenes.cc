// 에라토스테네스의 체
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;
int M, N;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

	vector<int> nums(N+1);
	nums[1] = 0;
	for (int i = 2; i <= N; i++) {
		nums[i] = i;
	}
	int sqrtN = sqrt(N);
	for (int i = 2; i <= sqrtN; i++) {
		if (nums[i]) {
			for (int j = i*i; j <= N; j += i) {
				nums[j] = 0;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (nums[i]) {
			cout << i << " ";
		}
	}
	return 0;
}