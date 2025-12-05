// bg 15655 N과 M(6)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void combination(vector<int>& num, vector<int>& result, int index) {
    if (result.size() == m) {
        for (int i=0; i<m; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
        return ;
    }

    for (int i=index; i<n; i++) {
        result.push_back(num[i]);
        combination(num, result, i + 1);
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<int> num(n);
    vector<int> result;

    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    combination(num, result, 0);
	
	return 0;
}