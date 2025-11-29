// bg 10808 알파벳 개수
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string word;
vector<int> num(26, 0);

int main() {
	cin >> word;

    // 범위 기반 - STL에서 유용함!
    for (char w : word) {
        num[w - 'a']++;
    }
    // 범위 기반을 사용하지 않는다면 다음과 같이 사용
    /*
    for (size_t i=0; i<word.size(); i++) {
        char w = word[i];
        num[w - 'a']++;
    }
    */
    for(int i = 0; i < 26; i++) {
        cout << num[i] << " ";
    }


	return 0;
}

