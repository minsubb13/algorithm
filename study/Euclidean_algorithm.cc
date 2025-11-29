// Euclidean algorithmn, 유클리드 호제법
#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

int gcd(int a, int b) {
	while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
	}
    return a;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> a >> b;
	
	int A = max(a, b);
	int B = min(a, b);

	int gcd_result = gcd(A, B);
    int lcm_result = A * B / gcd_result;
    cout << gcd_result << '\n';
    cout << lcm_result << '\n';
	
	return 0;
}