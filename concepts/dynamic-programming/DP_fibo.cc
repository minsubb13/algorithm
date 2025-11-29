#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp(10004, -1);

int fibo (int n) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibo(n-2) + fibo(n-1);
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n);

	return 0;
}