// bottom-up fibonacci
#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(10004, -1);

int fibo (int n) {
    if (n <= 1) return n;
    
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n) << '\n';

	return 0;
}