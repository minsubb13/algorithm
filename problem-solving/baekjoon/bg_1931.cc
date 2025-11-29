// bg 1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int result = 1;
vector<pair<int, int>> meeting;

bool sorting_func(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        return a.first < b.first;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    meeting.resize(n);

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meeting[i].first = s;
        meeting[i].second = e;
    }
    sort(meeting.begin(), meeting.end(), sorting_func);

    int end_time = meeting[0].second;
    for (int i = 1; i < n; i++) {
        if (meeting[i].first >= end_time) {
            result++;
            end_time = meeting[i].second;
        }
    }
    cout << result << '\n';
	return 0;
}