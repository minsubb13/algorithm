// bg 2828 사과 담기 게임
#include <iostream>
#include <queue>

using namespace std;

int n, m, j;
int cnt = 0;
queue<int> qu;

void solve(int current, int apple) {
    if (qu.empty()) {
        return ;
    }
    
    if (apple >= current && apple <= (current+m-1)) { // 바구니에 담길 때
        qu.pop();
        int next_apple = qu.front();
        solve(current, next_apple);
    }
    else if (apple >= (current+m-1)) { // 바구니보다 오른쪽에 담길 때
        cnt++;
        solve(current + 1, apple);
    }
    else { // 바구니보다 왼쪽에 담길 때
        cnt++;
        solve(current - 1, apple);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> j;

    for (int i=0; i<j; i++) {
        int a;
        cin >> a;
        qu.push(a);
    }

    int current = 1;
    int start = qu.front();

    solve(current, start);

    cout << cnt << '\n';

	return 0;
}