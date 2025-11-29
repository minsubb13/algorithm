// 재귀로 구현한 코드2
#include <iostream>
#include <vector>

using namespace std;

void Permutation(vector<bool> visited, vector<char> arr, vector<char> perm, int depth) {
    if (depth == perm.size()) {
        for (int i=0; i<perm.size(); i++) {
            cout << perm[i] << " ";
        }
        cout << '\n';
        return ;
    }

    for (int i=0; i<arr.size(); i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        perm[depth] = arr[i];
        Permutation(visited, arr, perm, depth + 1);
        visited[i] = 0;
    }
}

int main() {
    vector<char> vec = {'a', 'b', 'c', 'd'};
    const int n = vec.size();
    const int r = 2;
    vector<char> perm(r);
    vector<bool> visited(n);

    Permutation(visited, vec, perm, 0); // 4P2
	
	return 0;
}