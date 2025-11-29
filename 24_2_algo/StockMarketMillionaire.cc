/*
주식은 가격이 낮은 날에 사서 가격이 높을 때 팔 때 가장 큰 수익을 얻는다.
입력이 1 1 3 1 2 과 같을 때, 1, 2일에 사서 3일에 팔고 4일에 사서 5일에
팔 때 가장 큰 수익을 얻을 수 있다.
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
long long result = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> stock_price(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        stock_price[i] = a;
    }

    int max = stock_price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (max > stock_price[i]) {
            result += max - stock_price[i];
        }
        else {
            max = stock_price[i];
        }
    }

    cout << result << '\n';

	return 0;
}