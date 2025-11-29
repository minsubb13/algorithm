#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fibo(10004);

// 임의 정밀도 / 큰 수의 계산 필요
// n <= 100이므로 long long 자료형으로도 구현이 불가능하기 때문에 string 덧셈 구현이 필요하다
string string_add(string x, string y)
{
    int num;
    int carry = 0;
    string result;

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    // ascii code 이용, 자릿수 맞추기
    while (x.length() < y.length()) {
        x += '0';
    }
    while (x.length() > y.length()) {
        y += '0';
    }

    for (int i = 0; i < x.length(); ++i) {
        num = ((x[i] - '0') + (y[i] - '0') + carry) % 10; // e.g. 8+7=15, 5를 취하고 result에 추가
        result += to_string(num);
        carry = ((x[i] - '0') + (y[i] - '0') + carry) / 10; // carry 계산
    }
    if (carry != 0) {
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
	int n;
    cin >> n;

    fibo[0] = '0';
    fibo[1] = '1';

    // bottom-up 방식
    for (int i=2; i<=n; i++) {
        fibo[i] = string_add(fibo[i-1], fibo[i-2]);
    }

    cout << fibo[n] << '\n';

	return 0;
}