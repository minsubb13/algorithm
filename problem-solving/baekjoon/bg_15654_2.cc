// bg 15654 N과 M (5)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

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
    sort(numbers.begin(), numbers.end());

    do {
        for (int i=0; i<M; i++) {
            cout << numbers[i] << " ";
        }
        cout << '\n';
        reverse(numbers.begin() + M, numbers.end());
    } while (next_permutation(numbers.begin(), numbers.end()));

	return 0;
}