// bg 7568 덩치

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.second < b.second;
    }
    return a.second < b.second;
}

int main() {
    int person_num;
    cin >> person_num;

    vector<pair<int, int>> person(person_num);
    for (int num = 0; num < person_num; num++) {
        int kg, cm;
        cin >> kg >> cm;

        person[num] = make_pair(kg, cm);
    }

    vector<int> rank(person_num, 1);

    for (int i = 0; i < person_num; i++) {
        for (int j = 0; j < person_num; j++) {
            if (i != j && person[i].first < person[j].first && person[i].second < person[j].second) {
                rank[i]++;
            }
        }
    }
    
    for (int i = 0; i < person_num; i++) {
        cout << rank[i] << " ";
    }
	return 0;
}