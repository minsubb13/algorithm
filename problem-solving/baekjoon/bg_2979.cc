// 2979 트럭 주차
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> truck(3, vector<int>(100, 0));

int main() {
	int a, b, c;
    int fee = 0;
    cin >> a >> b >> c;

    for (int i=0; i<3; i++) {
        int enter, out;
        cin >> enter >> out;
        
        for (int j=enter; j<out; j++) {
            truck[i][j] = 1;
        }
    }
    
    for (int i=0; i<100; i++) {
        int sum = truck[0][i] + truck[1][i] + truck[2][i];
        if (sum == 1) {
            fee += a;
        }
        else if (sum == 2) {
            fee += (2*b);
        }
        else if (sum == 3) {
            fee += (3*c);
        }
        else {
            continue;
        }
    }

    cout << fee;

	return 0;
}