// 10988 펠린드롬인지 확인하기
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
    cin >> str;

    int end = str.size();

    int palindrome = 1;
    for (int i=0; i<end/2; i++) {
        if (str[i] != str[end-i-1]) {
            palindrome = 0;
            break;
        }
    }
    if (palindrome == 1) {
        cout << '1';
    }
    else {
        cout << '0';
    }

	return 0;
}