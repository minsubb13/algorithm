/*
연습문제 2: 빠르고 범용적인 데이터 저장 컨테이너 만들기
    모든 인자를 공통 타입으로 변환하여 저장하되, 전체 원소를 빠르게 순회할 수 있어야 함
*/


#include <array>
#include <iostream>
#include <type_traits>

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
}

int main() {
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for (auto i: data) 
        std::cout << i << " ";
    std::cout << std::endl;
}