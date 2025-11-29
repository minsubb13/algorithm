/* ** 누적합 무식하게 구현

#include <iostream>

using namespace std;

int a[100004], b, c, psum[100004], n, m;

int main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        int sum = 0;
        for (int j = b; j <= c; j++) {
            sum += a[j];
        }
        cout << sum << '\n';
    }
	return 0;
}
*/

// 누적합 구현
#include <iostream>

using namespace std;

int a[100004], b, c, psum[100004], n, m;

int main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i]; // 1부터 n까지 누적합
    }
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << '\n'; // b-1부터 c까지 부분합
    }

	return 0;
}