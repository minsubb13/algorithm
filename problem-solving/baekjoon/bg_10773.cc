// bg 10773 제로
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int sum =0;
int k;

int main() {
    cin >> k;

    for (int i=0; i<k; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            sum -= s.top();
            s.pop();
        }
        else {
            s.push(num);
            sum += num;
        }
        
    }
    cout << sum;	
	return 0;
}