#include <iostream>
#include <vector>

using namespace std;

int n, r;
int cnt = 0;
vector<int> num(8);
vector<bool> visited(8);
vector<int> result(8);

void Permutation(int depth) {
    if (depth == r) {
        cnt++;
        for (int i=0; i<r; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';

        return ;
    }

    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            result[depth] = num[i];
            Permutation(depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
	cin >> n >> r;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        num[i] = a;
    }
    sort(num.begin(), num.begin() + n);

    Permutation(0);
    cout << cnt << '\n';

	return 0;
}