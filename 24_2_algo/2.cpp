#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const vector<int>& candies, int left, int right) {
    while (left < right) {
        if (candies[left] != candies[right]) return false;
        left++;
        right--;
    }
    return true;
}

vector<int> removeGroup(const vector<int>& candies, int left, int right) {
    vector<int> result;
    for (int i = 0; i < left; i++) {
        result.push_back(candies[i]);
    }
    for (int i = right + 1; i < candies.size(); i++) {
        result.push_back(candies[i]);
    }
    return result;
}

int solve(vector<int> candies) {
    if (candies.empty()) return 0;
    
    int n = candies.size();
    if (n == 1) return 1;
    
    int result = n;
    
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start + len <= n; start++) {
            int end = start + len - 1;
            if (isPalindrome(candies, start, end)) {
                vector<int> remaining = removeGroup(candies, start, end);
                result = min(result, 1 + solve(remaining));
            }
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> candies(n);
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }
    
    cout << solve(candies) << endl;
    return 0;
}