// bg 1629 곱셈
#include <iostream>

using namespace std;
long long a, b, c;

long long power(long long base, long long expo) {
    if (expo == 0) {
        return 1;
    }
    if (expo == 1) {
        return base % c;
    }

    long long x = power(base, expo / 2) % c;
    if (expo % 2 == 1) {
        return (x * x % c * base) % c;
    }
    else {
        return x * x % c;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    long long ret = power(a, b);
    cout << ret << '\n';
	return 0;
}