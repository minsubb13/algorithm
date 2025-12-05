// bg 10808 알파벳 개수
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string word;
vector<int> num(26, 0);

int main() {
	cin >> word;

    for (int i=0; i<word.size(); i++) {
        if (word[i] == 'a') num[0]++;
        else if (word[i] == 'b') num[1]++;
        else if (word[i] == 'c') num[2]++;
        else if (word[i] == 'd') num[3]++;
        else if (word[i] == 'e') num[4]++;
        else if (word[i] == 'f') num[5]++;
        else if (word[i] == 'g') num[6]++;
        else if (word[i] == 'h') num[7]++;
        else if (word[i] == 'i') num[8]++;
        else if (word[i] == 'j') num[9]++;
        else if (word[i] == 'k') num[10]++;
        else if (word[i] == 'l') num[11]++;
        else if (word[i] == 'm') num[12]++;
        else if (word[i] == 'n') num[13]++;
        else if (word[i] == 'o') num[14]++;
        else if (word[i] == 'p') num[15]++;
        else if (word[i] == 'q') num[16]++;
        else if (word[i] == 'r') num[17]++;
        else if (word[i] == 's') num[18]++;
        else if (word[i] == 't') num[19]++;
        else if (word[i] == 'u') num[20]++;
        else if (word[i] == 'v') num[21]++;
        else if (word[i] == 'w') num[22]++;
        else if (word[i] == 'x') num[23]++;
        else if (word[i] == 'y') num[24]++;
        else { num[25]++; }
    }

    for (int i=0; i<num.size(); i++) {
        cout << num[i] << ' ';
    }

	return 0;
}

