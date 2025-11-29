// bg 15654 N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<bool> visited(8);

void Permutation(vector<int>& numbers, vector<int> result, int depth) {
    if (depth == result.size()) {
        for (int i=0; i<result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
        return ;
    }
    
    for (int i=0; i<N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            result[depth] = numbers[i];
            Permutation(numbers, result, depth+1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<int> numbers(N);
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        numbers[i] = a;
    }
    vector<int> result(M);

    sort(numbers.begin(), numbers.end());

    Permutation(numbers, result, 0);

	return 0;
}