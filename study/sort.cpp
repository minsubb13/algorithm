#include <iostream>
#include <vector>
#define MAX_SIZE 5
using namespace std;


void bubble_sort(vector<int> v) {
    for (int i=0; i<v.size()-1; i++) {
        if (v[i] < v[i+1]) {
            int temp;
            temp = v[i+1];
            v[i+1] = v[i];
            v[i] = temp;
        }
    }
}

void selection_sort();



int main() {
    int i;
    int n = MAX_SIZE;
    vector<int> v = {7, 4, 5, 1, 3};

    // 버블 정렬 수행
    bubble_sort(v);

    // 정렬 결과 출력
    for(i=0; i<n; i++){
      printf("%d\n", v[i]);
    }





    return 0;
}
