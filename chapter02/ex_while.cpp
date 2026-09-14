#include <iostream>
using namespace std;

int main() {
    int i{0};          // 1. 초기 상태

    while (i < 5) {    // 2. 반복 조건
        cout << i << '\n';
        ++i;           // 3. 상태 변화
    }

    return 0;
}
