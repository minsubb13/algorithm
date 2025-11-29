#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 2차원 벡터
    vector<vector<int>> v(5, vector<int>(5, 0));
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // 하나의 벡터에 100개의 원소를 담을 수 있는 벡터 1개 선언
    vector<int> v(100);
    // 100개의 벡터 배열 선언
    vector<int> v[100];




    return 0;
}