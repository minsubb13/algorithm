#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
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

int maxOverlap(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);

    int begin = 0, matched = 0;
    while (begin < n) {
        if (matched < m && a[begin + matched] == b[matched]) {
            ++matched;
            if(begin + matched ==n ) {
                return matched;
            }
        }
        else {
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return 0;
}


int main() {
    int tc;
    cin >> tc;

    for (int testcase=0; testcase<tc; ++testcase) {
        string word;
        cin >> word;

        string word_reverse = word;
        reverse(word_reverse.begin(), word_reverse.end());

        int result = maxOverlap(word, word_reverse);
        cout << word.size()*2 - result << endl;
    }
	return 0;
}