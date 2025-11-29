// bg 12865 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<pair<int, int>> knapsack(n);

    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        knapsack[i].first = weight;
        knapsack[i].second = value;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        int W = knapsack[i].first;
        int V = knapsack[i].second;
        for (int j = 1; j <= k; j++) {
            if (W > j) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	
	return 0;
}