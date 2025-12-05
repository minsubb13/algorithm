// bg 1153 네 개의 소수
#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int n;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    if (n < 8) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> nums(n+1);
    vector<int> primes;
    nums[1] = 0;
    for (int i = 2; i <= n; i++) {
        nums[i] = i;
    }
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++) {
        if (nums[i]) {
            for (int j = i*i; j <= n; j += i) {
                nums[j] = 0;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (nums[i]) {
            primes.push_back(nums[i]);
        }
    }

    if (n % 2 == 1) {
        n = n - 5;
        answer.push_back(2);
        answer.push_back(3);
    }
    else {
        n = n - 4;
        answer.push_back(2);
        answer.push_back(2);

    }

    for (auto prime : nums) {
        if (nums[n - prime]) {
            answer.push_back(prime);
            answer.push_back(n - prime);
            break;
        }
    }
    
    for (auto num : answer) {
        cout << num << " ";
    }

	return 0;
}