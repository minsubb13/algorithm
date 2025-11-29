#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int operation;
    cin >> operation;
    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int i=0; i<operation; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (minheap.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << minheap.top() << '\n';
                minheap.pop();
            }
        }
        else {
            minheap.push(num);
        }
        
    }

	return 0;
}
