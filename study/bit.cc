#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

	int numBits = static_cast<int>(std::floor(std::log2(n))) + 1;
    cout << numBits << endl;
    for (int i = numBits - 1; i >= 0; --i) {
        std::cout << ((n >> i) & 1);
    }
    std::cout << std::endl;

	return 0;
}