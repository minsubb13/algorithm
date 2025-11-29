#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void printheap(vector<int>& vec) {
    std::cout << "Heapified abilityay (Min-Heap): ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> ability = {4, 10, 3, 5, 1}; // 1, 3, 4, 5, 10
    make_heap(ability.begin(), ability.end(), greater<int>());

    printheap(ability);

    // 최소 힙에서 요소를 추출
    std::pop_heap(ability.begin(), ability.end(), std::greater<int>());

    printheap(ability);

    int minElement = ability.back();
    ability.pop_back(); // pop_heap은 최소값을 벡터의 마지막으로 옮긴다.
    // 맨 마지막 인자는 힙 아키텍처에 포함시키지 않은 상태의 재배열을 수행한다

    std::cout << "Popped minimum element: " << minElement << std::endl;

	return 0;
}