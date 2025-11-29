#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin >> n;
    
    int cnt = (n / 5) + (n / 25) + (n / 125);
    cout << cnt << '\n';

	return 0;
}