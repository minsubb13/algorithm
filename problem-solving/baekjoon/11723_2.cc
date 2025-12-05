// bg 11723 집합
#include <iostream>
#include <string>

using namespace std;

int m;
int S = 0, x;
string op;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> op;

        if (op == "add") {
            cin >> x;
            S |= (1 << x); // OR 연산자
        } else if (op == "remove") {
            cin >> x;
            S &= ~(1 << x);
        } else if (op == "check") {
            cin >> x;
            if ((S & (1 << x))) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (op == "toggle") {
            cin >> x;
            S ^= (1 << x);
        } else if (op == "all") {
            S = (1<<21) - 1;
        } else { // empty
            S = 0;
        }
    }
	return 0;
}