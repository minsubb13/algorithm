// bg 11723 집합
#include <iostream>
#include <string>

using namespace std;

int m;
bool S[21] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> m;

    for (int i=0; i<m; i++) {
        string ins;
        int x;
        cin >> ins;
        if (ins == "add") {
            cin >> x;
            S[x] = 1;
        } else if (ins == "remove") {
            cin >> x;
            S[x] = 0;
        } else if (ins == "check") {
            cin >> x;
            if (S[x] == 1) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (ins == "toggle") {
            cin >> x;
            if (S[x] == 1) {
                S[x] = 0;
            } else {
                S[x] = 1;
            }
        } else if (ins == "all") {
            for (int n=1; n<=20; n++) {
                S[n] = 1;
            }
        } else {
            for (int n=1; n<=20; n++) {
                S[n] = 0;
            }
        }
    }


	return 0;
}