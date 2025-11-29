// 재귀로 구현한 코드1
// 4P3
// 엄청 복잡하네
#include <iostream>

using namespace std;

int cnt = 0;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutation(char data[], int depth, int n, int r) {
    if (depth == r) {
        cnt++;
        for (int i=0; i<r; i++) {
            cout << data[i] << " ";
        }
        cout << '\n';
        return ;
    }

    for (int i=depth; i<n; i++) {
        swap(data[depth], data[i]);
        permutation(data, depth + 1, n, r);
        swap(data[depth], data[i]);
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd'};
    
    permutation(arr, 0, 4, 3);
    cout << cnt << '\n';
	
	return 0;
}