// bg 1644 소수의 연속합
#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

int n;
int answer = 0;
vector<int> nums;
vector<int> primes;

void make_prime() {
    nums.resize(n+1, 0);
    nums[1] = 0;
    for (int i=2; i<=n; i++) {
        nums[i] = i;
    }
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++) {
        if (nums[i]) {
            for (int j=i*i; j<=n; j+=i) {
                nums[j] = 0;
            }
        }
    }
    primes.push_back(0);
    for (int i=2; i<=n; i++) {
        if (nums[i]) {
            primes.push_back(nums[i]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    make_prime();

    int prime_size = primes.size();
    for (int i = 1; i <= prime_size; i++) {
        primes[i] += primes[i-1];
    }
    int left = 0;
    int right = 1;

    while (left < prime_size - 1 && right < prime_size) {
        if (primes[right] - primes[left] == n) {
            answer++;
            left++;
            right++;
        }
        else if (primes[right] - primes[left] > n) {
            left++;
        }
        else { // primes[right] - primes[left] < n
            right++;
        }
    }
    
    cout << answer << '\n';
	return 0;
}