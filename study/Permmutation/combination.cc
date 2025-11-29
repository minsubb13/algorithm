// 재귀로 combination

#include <iostream>
#include <vector>

using namespace std;

int n, r;

void Combination(vector<char> vec, vector<char> comb, int index, int depth) {
    if (depth == r) {
        for (int i=0; i<r; i++) {
            cout << comb[i] << " ";
        }
        cout << '\n';

        return ;
    }
    else {
        for (int i = index; i<n; i++) {
            comb[depth] = vec[i];
            Combination(vec, comb, i + 1, depth + 1);
        }
    }
}

int main() {
    vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
    n = vec.size();
    r = 3;
    vector<char> comb(r);

    Combination(vec, comb, 0, 0); // 5C3

	return 0;
}