// bg 17609 회문
#include <iostream>
#include <string>

using namespace std;
int n;

bool isPalindrome(string& word, int left, int right) {
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int palindrome (string& word) {
    int left = 0;
    int right = word.size() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            if (isPalindrome(word, left, right-1) || isPalindrome(word, left+1, right)) {
                return 1;
            }
            else {
                return 2;
            }
        }
        left++;
        right--;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int testcase = 0; testcase < n; testcase++) {
        string word;
        cin >> word;
        int result = palindrome(word);
        if (result == 0) {
            cout << 0 << '\n';
        }
        else if (result == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }

	return 0;
}