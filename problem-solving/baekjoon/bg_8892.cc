// Palindrome

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(vector<string>& word) {
    for (int i = 0; i < word.size(); i++) {
        for (int j = i + 1; j < word.size(); j++) {
            string check1 = word[i] + word[j];
            string check2 = word[j] + word[i];

            // check1이 펠린드롬인지 확인
            bool isPalindrome1 = true;
            for (int k = 0; k < check1.size() / 2; k++) {
                if (check1[k] != check1[check1.size() - 1 - k]) {
                    isPalindrome1 = false;
                    break;
                }
            }
            if (isPalindrome1) {
                return check1;
            }

            // check2가 펠린드롬인지 확인
            bool isPalindrome2 = true;
            for (int k = 0; k < check2.size() / 2; k++) {
                if (check2[k] != check2[check2.size() - 1 - k]) {
                    isPalindrome2 = false;
                    break;
                }
            }
            if (isPalindrome2) {
                return check2;
            }
        }
    }
    return "";
}

int main() {
    int tc;
    cin >> tc;

    for (int testcase = 0; testcase < tc; testcase++) {
        int word_num;
        cin >> word_num;
        vector<string> word(word_num);

        for (int i=0; i<word.size(); i++) {
            cin >> word[i];
        }
        string result = solve(word);

        if (result.empty()) {
            cout << "0" << endl;
        } else {
            cout << result << endl;
        }
    }
	return 0;
}