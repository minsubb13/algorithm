// bg 2210 숫자판 점프
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stack>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<vector<char>> mat(5, vector<char>(5));
stack<pair<int, int>> place_to_visit;
set<string> s;

void DFS(int y, int x) {
    string word;
    word.push_back(mat[y][x]);
    place_to_visit.push({y, x});
    
    while (!place_to_visit.empty()) {
        int cy = place_to_visit.top().first;
        int cx = place_to_visit.top().second;
        place_to_visit.pop();
        
        if (word.size() == 6) {
            s.insert(word);
            return ;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
                word.push_back(mat[ny][nx]);
                place_to_visit.push({ny, nx});
            }
        }
    }
    
    // 함수 종료 시 스택 비우기
    while (!place_to_visit.empty()) {
        place_to_visit.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            char a;
            cin >> a;
            mat[i][j] = a;
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            DFS(i, j);
        }
    }
    cout << s.size();
	
	return 0;
}