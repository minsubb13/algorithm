// 곱셈
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;

    int A, B, C;
    for (int i = 1; i <= b; i++) {
        int r = a % c;
        a = (r * a) % c;
    }

    cout << a;
	return 0;
}