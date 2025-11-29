#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    while(b >= a) {
        cout << a << " ";

        if ((a % 2) == 0) {
            a = a + 3;
        }
        else {
            a = a * 2;
        }
    }
	return 0;
}