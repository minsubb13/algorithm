// power 계산, divided-and-conquer
#include <iostream>

using namespace std;

long long power(long long base, long long exponent) {
    if (exponent == 1) {
        return base;
    }

    long long x = power(base, exponent / 2);
    if (exponent % 2 == 1) {
        return x * x * base;
    }
    else {
        return x * x;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    long long ret = power(a, b);
    cout << ret << '\n';
	return 0;
}