#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int matched = 0;
    for (int i = 0; i < n; i++) {
        while (matched > 0 && H[i] != N[matched])
            matched = pi[matched - 1];
        
        if (H[i] == N[matched]) {
            ++matched;
            if (matched == m) {
                ret.push_back(i - m + 2);  // 1-based index
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    
    vector<int> ret = kmpSearch(text, pattern);
    
    cout << ret.size() << '\n';
    for (int pos : ret) {
        cout << pos << ' ';
    }
    cout << '\n';
    
    return 0;
}