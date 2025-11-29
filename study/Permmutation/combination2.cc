#include <iostream>
#include <vector>

using namespace std;

int n, r;
vector<int> num(5);
vector<int> result(3);

void combi(int start, vector<int> result) {
    if (result.size() == r) {
        for (int i=0; i<r; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';

        return ;
    }

    for (int i = start + 1; i<n; i++) {
        result.push_back(num[i]);
        combi(start + 1, result);
        result.pop_back();
    }
}

int main() {
    n = 5;
    r = 3;

    num = {1, 2, 3, 4, 5};

    combi(0, result);
	
	return 0;
}